
#import "KeyCaptureSingleton.h"
#import <AudioToolbox/AudioToolbox.h>
#import <MediaPlayer/MediaPlayer.h>

@interface KeyCaptureSingleton()

-(void)initializeVolumeButtonCapture;
-(void)volumeDown;
-(void)volumeUp;
-(void)startCapturingVolumeButtonEvents;
-(void)stopCapturingVolumeButtonEvents;

@property BOOL isCapturingVolumeButtons;
@property BOOL suspended;
@property (retain) UIView *volumeView;

@end

NSString* keyUp = @"up";
NSString* keyDown = @"down";
NSString* allKeys = @"all";

#define IPHONE_VOLUME_UP_CODE = 10
#define IPHONE_VOLUME_DOWN_CODE = 11


@implementation KeyCaptureSingleton

// capture volume buttons
@synthesize upBlock;
@synthesize downBlock;
@synthesize launchVolume;
@synthesize isCapturingVolumeButtons = _isCapturingVolumeButtons;
@synthesize suspended = _suspended;
@synthesize volumeView = _volumeView;
@synthesize keyCaptureCallbacks;

void volumeListenerCallback (
                             void                      *inClientData,
                             AudioSessionPropertyID    inID,
                             UInt32                    inDataSize,
                             const void                *inData
                             );
void volumeListenerCallback (
                             void                      *inClientData,
                             AudioSessionPropertyID    inID,
                             UInt32                    inDataSize,
                             const void                *inData
                             ){
    const float *volumePointer = inData;
    float volume = *volumePointer;

    //NSLog(@" VOLUME = [%@],  VOLUME FROM PLAYER = [%@], LAUNCH_VOLUME = [%@]", [NSNumber numberWithDouble:volume], [NSNumber numberWithDouble:[[MPMusicPlayerController applicationMusicPlayer] volume]], [NSNumber numberWithDouble:[(KeyCaptureSingleton*)inClientData launchVolume]]);
    if( volume > [(KeyCaptureSingleton*)inClientData launchVolume] )
    {
        [(KeyCaptureSingleton*)inClientData volumeUp];
    }
    else if( volume < [(KeyCaptureSingleton*)inClientData launchVolume] )
    {
        [(KeyCaptureSingleton*)inClientData volumeDown];
    }

}

-(void)volumeDown
{
    AudioSessionRemovePropertyListenerWithUserData(kAudioSessionProperty_CurrentHardwareOutputVolume, volumeListenerCallback, self);

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.05 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //NSLog(@" GET VOLUME= [%@]", [NSNumber numberWithDouble:[[MPMusicPlayerController applicationMusicPlayer] volume]]);
        [[MPMusicPlayerController applicationMusicPlayer] setVolume:launchVolume];
        //NSLog(@" SET VOLUME TO = [%@]", [NSNumber numberWithDouble:launchVolume]);
        //NSLog(@" GET VOLUME= [%@]", [NSNumber numberWithDouble:[[MPMusicPlayerController applicationMusicPlayer] volume]]);
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.05 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self initializeVolumeButtonCapture];
        });
    });


    if( self.downBlock )
    {
        self.downBlock();
    }
}

-(void)volumeUp
{
    AudioSessionRemovePropertyListenerWithUserData(kAudioSessionProperty_CurrentHardwareOutputVolume, volumeListenerCallback, self);

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.05 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //NSLog(@" GET VOLUME= [%@]", [NSNumber numberWithDouble:[[MPMusicPlayerController applicationMusicPlayer] volume]]);
        [[MPMusicPlayerController applicationMusicPlayer] setVolume:launchVolume];
        //NSLog(@" SET VOLUME TO = [%@]", [NSNumber numberWithDouble:launchVolume]);
        //NSLog(@" GET VOLUME= [%@]", [NSNumber numberWithDouble:[[MPMusicPlayerController applicationMusicPlayer] volume]]);

        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.05 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self initializeVolumeButtonCapture];
        });
    });

    //[[MPMusicPlayerController applicationMusicPlayer] setVolume:launchVolume];
    //[self performSelector:@selector(initializeVolumeButtonCapture) withObject:self afterDelay:0.05];

    if( self.upBlock )
    {
        self.upBlock();
    }

}

-(id)init
{
    self = [super init];
    if( self )
    {
        self.isCapturingVolumeButtons = NO;
        self.suspended = NO;
        callbackHolder = nil;

        [self setKeyCaptureCallbacks:[NSMutableDictionary new]];

        self.upBlock = ^{
            id<IMethodResult> cb = [keyCaptureCallbacks objectForKey:keyUp];
            if ( cb != nil)
            {
                NSMutableDictionary *res = [[NSMutableDictionary alloc] init];
                [res setObject:IPHONE_VOLUME_UP forKey:HK_KEY_VALUE];
                [cb setResult:res];
            }
        };
        self.downBlock = ^{
            id<IMethodResult> cb = [keyCaptureCallbacks objectForKey:keyDown];
            if ( cb != nil)
            {
                NSMutableDictionary *res = [NSMutableDictionary new];
                [res setObject:IPHONE_VOLUME_DOWN forKey:HK_KEY_VALUE];
                [cb setResult:res];
            }
        };
    }
    return self;
}


-(void)startCapturingVolumeButtonEvents
{
    NSAssert([[NSThread currentThread] isMainThread], @"This must be called from the main thread");

    if(self.isCapturingVolumeButtons) {
        return;
    }

    self.isCapturingVolumeButtons = YES;

    AudioSessionInitialize(NULL, NULL, NULL, NULL);
    AudioSessionSetActive(YES);

    launchVolume = [[MPMusicPlayerController applicationMusicPlayer] volume];
    savedLaunchVolume = launchVolume;
    hadToLowerVolume = launchVolume > 0.8750;
    hadToRaiseVolume = launchVolume < 0.1250;

    // Avoid flashing the volume indicator
    if (hadToLowerVolume || hadToRaiseVolume)
    {
        dispatch_async(dispatch_get_current_queue(), ^{
            if( hadToLowerVolume )
            {
                [[MPMusicPlayerController applicationMusicPlayer] setVolume:0.8750];
                launchVolume = 0.8750;
            }

            if( hadToRaiseVolume )
            {
                [[MPMusicPlayerController applicationMusicPlayer] setVolume:0.1250];
                launchVolume = 0.1250;
            }
        });
    }

    CGRect frame = CGRectMake(0, -100, 10, 0);
    self.volumeView = [[[MPVolumeView alloc] initWithFrame:frame] autorelease];
    [self.volumeView sizeToFit];
    [[[[UIApplication sharedApplication] windows] objectAtIndex:0] addSubview:self.volumeView];

    [self initializeVolumeButtonCapture];

    if (!self.suspended)
    {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(suspendCapturingVolumeButtonEvents:)
                                                     name:UIApplicationWillResignActiveNotification     // -> Inactive
                                                   object:nil];

        // Observe notifications that trigger resume
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(resumeCapturingVolumeButtonEvents:)
                                                     name:UIApplicationDidBecomeActiveNotification      // <- Active
                                                   object:nil];
    }
}

- (void)suspendCapturingVolumeButtonEvents:(NSNotification *)notification
{
    if(self.isCapturingVolumeButtons)
    {
        self.suspended = YES; // Call first!
        [self stopCapturingVolumeButtonEvents];
    }
}

- (void)resumeCapturingVolumeButtonEvents:(NSNotification *)notification
{
    if(self.suspended)
    {
        [self startCapturingVolumeButtonEvents];
        self.suspended = NO; // Call last!
    }
}

-(void)stopCapturingVolumeButtonEvents
{
    NSAssert([[NSThread currentThread] isMainThread], @"This must be called from the main thread");

    if(!self.isCapturingVolumeButtons)
    {
        return;
    }

    // Stop observing all notifications
    if (!self.suspended)
    {
        [[NSNotificationCenter defaultCenter] removeObserver:self];
    }

    AudioSessionRemovePropertyListenerWithUserData(kAudioSessionProperty_CurrentHardwareOutputVolume, volumeListenerCallback, self);


    [[MPMusicPlayerController applicationMusicPlayer] setVolume:savedLaunchVolume];

    if( hadToLowerVolume )
    {
        //[[MPMusicPlayerController applicationMusicPlayer] setVolume:1.0];
    }
    if( hadToRaiseVolume )
    {
        //[[MPMusicPlayerController applicationMusicPlayer] setVolume:0.0];
    }

    [self.volumeView removeFromSuperview];
    self.volumeView = nil;

    AudioSessionSetActive(NO);

    self.isCapturingVolumeButtons = NO;
}

-(void)dealloc
{
    self.suspended = NO;
    [self stopCapturingVolumeButtonEvents];

    [keyCaptureCallbacks removeObjectForKey:keyUp];
    [keyCaptureCallbacks removeObjectForKey:keyDown];
    [self setKeyCaptureCallbacks:nil];


    self.upBlock = nil;
    self.downBlock = nil;

    [super dealloc];
}

-(void)initializeVolumeButtonCapture
{
    AudioSessionAddPropertyListener(kAudioSessionProperty_CurrentHardwareOutputVolume, volumeListenerCallback, self);
}


-(void) getHomeKeyValue:(id<IMethodResult>)methodResult {

}

-(void) setHomeKeyValue:(NSString*)homeKeyValue methodResult:(id<IMethodResult>)methodResult {

}

-(void) captureKey:(BOOL)dispatch keyValue:(NSString*)keyValue methodResult:(id<IMethodResult>)methodResult {

    if ([keyValue caseInsensitiveCompare:@"all"]==NSOrderedSame)
    {
        if ([methodResult hasCallback])
        {
            [keyCaptureCallbacks setObject:methodResult forKey:keyUp];
            [keyCaptureCallbacks setObject:methodResult forKey:keyDown];
        }
        else
        {
            [keyCaptureCallbacks removeObjectForKey:keyUp];
            [keyCaptureCallbacks removeObjectForKey:keyDown];
        }
    }
    else
    {

        NSString* key = @"";

        if ( [keyValue caseInsensitiveCompare:IPHONE_VOLUME_UP]==NSOrderedSame )
        {
            key = keyUp;
        }
        else
        if ( [keyValue caseInsensitiveCompare:IPHONE_VOLUME_DOWN]==NSOrderedSame )
        {
            key = keyDown;
        }
        if (key != @"")
        {
            if ([methodResult hasCallback])
            {
                [keyCaptureCallbacks setObject:methodResult forKey:key];
            }
            else
            {
                [keyCaptureCallbacks removeObjectForKey:key];
            }
        }
    }

    if ([keyCaptureCallbacks count] > 0)
    {
        if (!self.isCapturingVolumeButtons)
        {
            callbackHolder = methodResult;
            [self startCapturingVolumeButtonEvents];
        }
    }
    else
    {
        if (self.isCapturingVolumeButtons)
        {
            [self stopCapturingVolumeButtonEvents];
        }
    }

}

-(void) remapKey:(NSString*)keyValue remapTo:(NSString*)remapTo methodResult:(id<IMethodResult>)methodResult{

}

-(void) captureTrigger:(id<IMethodResult>)methodResult {

}





@end
