//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#pragma mark Function Pointers and Blocks

typedef void (*CDUnknownFunctionPointerType)(void); // return type and parameters are unknown

typedef void (^CDUnknownBlockType)(void); // return type and parameters are unknown

#pragma mark Named Structures



#pragma mark -

//
// File: /Applications/Xcode.app/Contents/Developer/Library/PrivateFrameworks/CoreSimulator.framework/Versions/A/CoreSimulator
// UUID: BBAB8ABC-E9A0-3E35-82B7-C8850A186303
//
//                           Arch: x86_64
//                Current version: 89.0.0
//          Compatibility version: 1.0.0
//                 Source version: 89.0.0.0.0
//       Minimum Mac OS X version: 10.9.0
//                    SDK version: 10.9.0
//
// Objective-C Garbage Collection: Unsupported
//

@protocol SimDeviceNotifier
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(NSObject<OS_dispatch_queue> *)arg1 handler:(void (^)(NSDictionary *))arg2;
- (unsigned long long)registerNotificationHandler:(void (^)(NSDictionary *))arg1;
@end

@interface SimDeviceNotificationManager : NSObject <SimDeviceNotifier>
{
    NSObject<OS_dispatch_queue> *_handlersQueue;
    NSMutableDictionary *_handlers;
    unsigned long long _next_regID;
    NSObject<OS_dispatch_queue> *_sendQueue;
}

@property(retain) NSObject<OS_dispatch_queue> *sendQueue; // @synthesize sendQueue=_sendQueue;
@property unsigned long long next_regID; // @synthesize next_regID=_next_regID;
@property(retain) NSMutableDictionary *handlers; // @synthesize handlers=_handlers;
@property(retain) NSObject<OS_dispatch_queue> *handlersQueue; // @synthesize handlersQueue=_handlersQueue;
- (void)sendNotification:(id)arg1;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (id)init;

@end

@interface SimVerifier : NSObject
{
    NSObject<OS_xpc_object> *_serviceConnection;
    NSObject<OS_dispatch_queue> *_serviceConnectionQueue;
}

+ (id)verificationError:(int)arg1;
+ (id)connectionError;
+ (id)sharedVerifier;
@property(retain) NSObject<OS_dispatch_queue> *serviceConnectionQueue; // @synthesize serviceConnectionQueue=_serviceConnectionQueue;
@property(retain) NSObject<OS_xpc_object> *serviceConnection; // @synthesize serviceConnection=_serviceConnection;
- (id)verifyDyldSim:(id)arg1;
- (id)verifyAll;
- (BOOL)verifyAllWithError:(id *)arg1;
- (void)dealloc;
- (id)init;

@end

@interface SimServiceContext : NSObject
{
    long long _connectionType;
    NSObject<OS_xpc_object> *_serviceConnection;
    NSObject<OS_dispatch_queue> *_serviceConnectionQueue;
    NSDate *_lastConnectionTime;
}

+ (void)setSharedContextConnectionType:(long long)arg1;
+ (id)simContextWithConnectionType:(long long)arg1;
+ (id)sharedServiceContext;
@property(retain) NSDate *lastConnectionTime; // @synthesize lastConnectionTime=_lastConnectionTime;
@property(retain) NSObject<OS_dispatch_queue> *serviceConnectionQueue; // @synthesize serviceConnectionQueue=_serviceConnectionQueue;
@property(retain) NSObject<OS_xpc_object> *serviceConnection; // @synthesize serviceConnection=_serviceConnection;
@property long long connectionType; // @synthesize connectionType=_connectionType;
- (void)handleXPCEvent:(id)arg1;
- (void)dealloc;
- (void)connect;
- (void)reloadServiceIfMoved;
- (id)initWithConnectionType:(long long)arg1;
- (id)init;

@end

@interface SimDevice : NSObject <SimDeviceNotifier>
{
    unsigned long long _state;
    NSString *_name;
    NSMutableDictionary *_headServicePorts;
    NSString *_deviceTypeIdentifier;
    NSString *_runtimeIdentifier;
    NSUUID *_UDID;
    SimDeviceSet *_deviceSet;
    SimServiceContext *_serviceContext;
    NSString *_setPath;
    SimDeviceNotificationManager *_notificationManager;
    NSObject<OS_dispatch_queue> *_bootstrapQueue;
    NSMutableDictionary *_registeredServices;
    NSObject<OS_dispatch_queue> *_stateVariableQueue;
    NSMachPort *_deathTriggerPort;
    NSMachPort *_hostSupportPort;
    NSMutableArray *_darwinNotificationTokens;
    SimDevice *_pairedDevice;
    unsigned long long _pairedDeviceNotificationRegID;
    NSObject<OS_dispatch_queue> *_pairingQueue;
    NSObject<OS_dispatch_source> *_pairingDisconnectSource;
}

+ (BOOL)isValidState:(unsigned long long)arg1;
+ (id)simDevice:(id)arg1 UDID:(id)arg2 deviceTypeIdentifier:(id)arg3 runtimeIdentifier:(id)arg4 state:(unsigned long long)arg5 serviceContext:(id)arg6 setPath:(id)arg7;
+ (id)simDeviceAtPath:(id)arg1 serviceContext:(id)arg2;
+ (id)createDeviceWithName:(id)arg1 serviceContext:(id)arg2 setPath:(id)arg3 deviceType:(id)arg4 runtime:(id)arg5;
@property(retain) NSObject<OS_dispatch_source> *pairingDisconnectSource; // @synthesize pairingDisconnectSource=_pairingDisconnectSource;
@property(retain) NSObject<OS_dispatch_queue> *pairingQueue; // @synthesize pairingQueue=_pairingQueue;
@property unsigned long long pairedDeviceNotificationRegID; // @synthesize pairedDeviceNotificationRegID=_pairedDeviceNotificationRegID;
@property(retain) SimDevice *pairedDevice; // @synthesize pairedDevice=_pairedDevice;
@property(retain) NSMutableArray *darwinNotificationTokens; // @synthesize darwinNotificationTokens=_darwinNotificationTokens;
@property(retain, nonatomic) NSMachPort *hostSupportPort; // @synthesize hostSupportPort=_hostSupportPort;
@property(retain) NSMachPort *deathTriggerPort; // @synthesize deathTriggerPort=_deathTriggerPort;
@property(retain) NSObject<OS_dispatch_queue> *stateVariableQueue; // @synthesize stateVariableQueue=_stateVariableQueue;
@property(retain) NSMutableDictionary *registeredServices; // @synthesize registeredServices=_registeredServices;
@property(retain) NSObject<OS_dispatch_queue> *bootstrapQueue; // @synthesize bootstrapQueue=_bootstrapQueue;
@property(retain) SimDeviceNotificationManager *notificationManager; // @synthesize notificationManager=_notificationManager;
@property(copy) NSString *setPath; // @synthesize setPath=_setPath;
@property(retain) SimServiceContext *serviceContext; // @synthesize serviceContext=_serviceContext;
@property(readonly) SimDeviceSet *deviceSet; // @synthesize deviceSet=_deviceSet;
@property(copy) NSUUID *UDID; // @synthesize UDID=_UDID;
@property(copy) NSString *runtimeIdentifier; // @synthesize runtimeIdentifier=_runtimeIdentifier;
@property(copy) NSString *deviceTypeIdentifier; // @synthesize deviceTypeIdentifier=_deviceTypeIdentifier;
- (void)cancelPairedDeviceMonitoring;
- (void)beginPairedDeviceMonitoring:(id)arg1;
- (id)portForServiceNamed:(id)arg1 error:(id *)arg2;
- (void)registerHeadServicePorts;
@property(readonly) NSMutableDictionary *headServicePorts; // @synthesize headServicePorts=_headServicePorts;
- (BOOL)isAvailableWithError:(id *)arg1;
@property(readonly) BOOL available;
- (BOOL)triggerCloudSyncWithError:(id *)arg1;
- (void)triggerCloudSyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)darwinNotificationSetState:(unsigned long long)arg1 name:(id)arg2 error:(id *)arg3;
- (BOOL)darwinNotificationGetState:(unsigned long long *)arg1 name:(id)arg2 error:(id *)arg3;
- (BOOL)postDarwinNotification:(id)arg1 error:(id *)arg2;
- (int)launchApplicationWithID:(id)arg1 options:(id)arg2 error:(id *)arg3;
- (void)launchApplicationAsyncWithID:(id)arg1 options:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (id)installedAppsWithError:(id *)arg1;
- (id)propertiesOfApplication:(id)arg1 error:(id *)arg2;
- (BOOL)applicationIsInstalled:(id)arg1 type:(id *)arg2 error:(id *)arg3;
- (BOOL)uninstallApplication:(id)arg1 withOptions:(id)arg2 error:(id *)arg3;
- (BOOL)installApplication:(id)arg1 withOptions:(id)arg2 error:(id *)arg3;
- (BOOL)setKeyboardLanguage:(id)arg1 error:(id *)arg2;
- (BOOL)addPhoto:(id)arg1 error:(id *)arg2;
- (BOOL)openURL:(id)arg1 error:(id *)arg2;
- (long long)compare:(id)arg1;
- (id)newDeviceNotification;
- (id)createXPCNotification:(const char *)arg1;
- (id)createXPCRequest:(const char *)arg1;
- (void)handleXPCRequestSpawn:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestGetenv:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestLookup:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUnregister:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRegister:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRestore:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestErase:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestUpgrade:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestShutdown:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestBoot:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestRename:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequest:(id)arg1 peer:(id)arg2;
- (void)handleXPCNotificationDeviceRenamed:(id)arg1;
- (void)handleXPCNotificationDeviceStateChanged:(id)arg1;
- (void)handleXPCNotification:(id)arg1;
- (void)setName:(id)arg1;
@property(readonly, copy) NSString *name;
- (void)setState:(unsigned long long)arg1;
@property(readonly) unsigned long long state;
- (id)stateString;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (void)simulateMemoryWarning;
- (id)memoryWarningFilePath;
@property(readonly, copy) NSString *logPath;
- (id)dataPath;
- (id)devicePath;
- (id)environment;
- (int)_spawnFromSelfWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (int)_spawnFromLaunchdWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (int)spawnWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 error:(id *)arg4;
- (void)spawnAsyncWithPath:(id)arg1 options:(id)arg2 terminationHandler:(CDUnknownBlockType)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (BOOL)unregisterService:(id)arg1 error:(id *)arg2;
- (BOOL)registerPort:(unsigned int)arg1 service:(id)arg2 error:(id *)arg3;
- (unsigned int)lookup:(id)arg1 error:(id *)arg2;
- (unsigned int)_lookup:(id)arg1 error:(id *)arg2;
- (id)getenv:(id)arg1 error:(id *)arg2;
- (BOOL)restoreContentsAndSettingsFromDevice:(id)arg1 error:(id *)arg2;
- (void)restoreContentsAndSettingsAsyncFromDevice:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)eraseContentsAndSettingsWithError:(id *)arg1;
- (BOOL)_bq_eraseContentsAndSettingsWithError:(id *)arg1;
- (void)eraseContentsAndSettingsAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)upgradeToRuntime:(id)arg1 error:(id *)arg2;
- (void)upgradeAsyncToRuntime:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)rename:(id)arg1 error:(id *)arg2;
- (void)renameAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (BOOL)shutdownWithError:(id *)arg1;
- (BOOL)_shutdownWithError:(id *)arg1;
- (void)shutdownAsyncWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)bootWithOptions:(id)arg1 error:(id *)arg2;
- (void)bootAsyncWithOptions:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (void)launchdDeathHandlerWithDeathPort:(id)arg1;
- (BOOL)startLaunchdWithDeathPort:(id)arg1 deathHandler:(CDUnknownBlockType)arg2 error:(id *)arg3;
- (void)registerPortsWithLaunchd;
@property(readonly) NSArray *launchDaemonsPaths;
- (BOOL)removeLaunchdJobWithError:(id *)arg1;
- (BOOL)createLaunchdJobWithError:(id *)arg1 extraEnvironment:(id)arg2 disabledJobs:(id)arg3;
- (BOOL)createDarwinNotificationProxiesWithError:(id *)arg1;
- (BOOL)createDarwinNotificationProxy:(id)arg1 toSimAs:(id)arg2 withState:(BOOL)arg3 error:(id *)arg4;
- (BOOL)clearTmpWithError:(id *)arg1;
- (BOOL)ensureLogPathsWithError:(id *)arg1;
- (BOOL)supportsFeature:(id)arg1;
@property(readonly, copy) NSString *launchdJobName;
- (void)saveToDisk;
- (id)saveStateDict;
- (void)validateAndFixState;
@property(readonly, retain) SimRuntime *runtime;
@property(readonly, retain) SimDeviceType *deviceType;
@property(readonly, copy) NSString *descriptiveName;
- (id)description;
- (id)initDevice:(id)arg1 UDID:(id)arg2 deviceTypeIdentifier:(id)arg3 runtimeIdentifier:(id)arg4 state:(unsigned long long)arg5 serviceContext:(id)arg6 setPath:(id)arg7;

@end

@interface SimDeviceType : NSObject
{
    float _mainScreenScale;
    unsigned int _minRuntimeVersion;
    unsigned int _maxRuntimeVersion;
    unsigned int _minCoreSimulatorFrameworkVersion;
    unsigned int _maxCoreSimulatorFrameworkVersion;
    NSString *_name;
    NSString *_identifier;
    NSString *_modelIdentifier;
    NSBundle *_bundle;
    NSArray *_supportedArchs;
    NSArray *_supportedProductFamilyIDs;
    NSDictionary *_capabilities;
    NSString *_springBoardConfigName;
    NSString *_productClass;
    NSDictionary *_environment_extra;
    NSDictionary *_aliases;
    NSDictionary *_supportedFeatures;
    NSDictionary *_supportedFeaturesConditionalOnRuntime;
    struct CGSize _mainScreenSize;
    struct CGSize _mainScreenDPI;
}

+ (void)supportedDeviceTypesAddProfilesAtPath:(id)arg1;
+ (id)supportedDeviceTypesByAlias;
+ (id)supportedDeviceTypesByIdentifier;
+ (id)supportedDeviceTypes;
+ (id)supportedDevices;
@property(copy) NSDictionary *supportedFeaturesConditionalOnRuntime; // @synthesize supportedFeaturesConditionalOnRuntime=_supportedFeaturesConditionalOnRuntime;
@property(copy) NSDictionary *supportedFeatures; // @synthesize supportedFeatures=_supportedFeatures;
@property(copy) NSDictionary *aliases; // @synthesize aliases=_aliases;
@property(copy) NSDictionary *environment_extra; // @synthesize environment_extra=_environment_extra;
@property(copy) NSString *productClass; // @synthesize productClass=_productClass;
@property(copy) NSString *springBoardConfigName; // @synthesize springBoardConfigName=_springBoardConfigName;
@property unsigned int maxCoreSimulatorFrameworkVersion; // @synthesize maxCoreSimulatorFrameworkVersion=_maxCoreSimulatorFrameworkVersion;
@property unsigned int minCoreSimulatorFrameworkVersion; // @synthesize minCoreSimulatorFrameworkVersion=_minCoreSimulatorFrameworkVersion;
@property unsigned int maxRuntimeVersion; // @synthesize maxRuntimeVersion=_maxRuntimeVersion;
@property unsigned int minRuntimeVersion; // @synthesize minRuntimeVersion=_minRuntimeVersion;
@property struct CGSize mainScreenDPI; // @synthesize mainScreenDPI=_mainScreenDPI;
@property struct CGSize mainScreenSize; // @synthesize mainScreenSize=_mainScreenSize;
@property(copy) NSDictionary *capabilities; // @synthesize capabilities=_capabilities;
@property float mainScreenScale; // @synthesize mainScreenScale=_mainScreenScale;
@property(copy) NSArray *supportedProductFamilyIDs; // @synthesize supportedProductFamilyIDs=_supportedProductFamilyIDs;
@property(copy) NSArray *supportedArchs; // @synthesize supportedArchs=_supportedArchs;
@property(retain) NSBundle *bundle; // @synthesize bundle=_bundle;
@property(copy) NSString *modelIdentifier; // @synthesize modelIdentifier=_modelIdentifier;
@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *name; // @synthesize name=_name;
- (Class)deviceClass;
- (long long)compare:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (id)environmentForRuntime:(id)arg1;
- (id)environment;
@property(readonly, copy) NSString *productFamily;
@property(readonly) int productFamilyID;
- (id)description;
- (id)initWithBundle:(id)arg1;
- (id)initWithPath:(id)arg1;
- (id)init;

@end

@interface SimDeviceSet : NSObject <SimDeviceNotifier>
{
    NSString *_setPath;
    NSObject<OS_dispatch_queue> *_devicesQueue;
    NSMutableDictionary *__devicesByUDID;
    NSMutableDictionary *_devicesNotificationRegIDs;
    NSMutableDictionary *__devicePairsByUUID;
    SimServiceContext *_serviceContext;
    SimDeviceNotificationManager *_notificationManager;
    NSDictionary *_defaultCreatedDevices;
}

+ (void)resubscribeAllToNotificationsInContext:(id)arg1;
+ (id)allSets;
+ (id)setForSetPath:(id)arg1 serviceContext:(id)arg2;
+ (id)setForSetPath:(id)arg1;
+ (id)defaultSet;
+ (id)defaultSetPath;
@property(retain) NSDictionary *defaultCreatedDevices; // @synthesize defaultCreatedDevices=_defaultCreatedDevices;
@property(retain) SimDeviceNotificationManager *notificationManager; // @synthesize notificationManager=_notificationManager;
@property(retain) SimServiceContext *serviceContext; // @synthesize serviceContext=_serviceContext;
@property(retain) NSMutableDictionary *_devicePairsByUUID; // @synthesize _devicePairsByUUID=__devicePairsByUUID;
@property(retain) NSMutableDictionary *devicesNotificationRegIDs; // @synthesize devicesNotificationRegIDs=_devicesNotificationRegIDs;
@property(retain) NSMutableDictionary *_devicesByUDID; // @synthesize _devicesByUDID=__devicesByUDID;
@property(retain) NSObject<OS_dispatch_queue> *devicesQueue; // @synthesize devicesQueue=_devicesQueue;
@property(copy) NSString *setPath; // @synthesize setPath=_setPath;
- (void)handleXPCRequestUnpair:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestPair:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequestDeleteDevice:(id)arg1 peer:(id)arg2 device:(id)arg3;
- (void)handleXPCRequestCreateDevice:(id)arg1 peer:(id)arg2;
- (void)handleXPCRequest:(id)arg1 peer:(id)arg2;
- (void)handleXPCNotificationDevicePairRemoved:(id)arg1;
- (void)handleXPCNotificationDevicePairAdded:(id)arg1;
- (void)handleXPCNotificationDeviceRemoved:(id)arg1;
- (void)handleXPCNotificationDeviceAdded:(id)arg1;
- (void)handleXPCNotification:(id)arg1;
- (BOOL)unpairDevicePair:(id)arg1 error:(id *)arg2;
- (void)unpairDevicePairAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (id)createDevicePairWithGizmo:(id)arg1 companion:(id)arg2 error:(id *)arg3;
- (void)createDevicePairAsyncWithGizmo:(id)arg1 companion:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (BOOL)deleteDevice:(id)arg1 error:(id *)arg2;
- (void)deleteDeviceAsync:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;
- (id)createDeviceWithType:(id)arg1 runtime:(id)arg2 name:(id)arg3 error:(id *)arg4;
- (void)createDeviceAsyncWithType:(id)arg1 runtime:(id)arg2 name:(id)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (BOOL)unregisterNotificationHandler:(unsigned long long)arg1 error:(id *)arg2;
- (void)sendNotification:(id)arg1;
- (unsigned long long)registerNotificationHandlerOnQueue:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (unsigned long long)registerNotificationHandler:(CDUnknownBlockType)arg1;
- (void)removeDevicePairAsync:(id)arg1;
- (void)addDevicePair:(id)arg1;
- (void)addDevicePairAsync:(id)arg1;
- (void)removeDeviceAsync:(id)arg1;
- (void)addDevice:(id)arg1;
- (void)addDeviceAsync:(id)arg1;
- (void)updateDefaultDevices;
- (id)devicePairsContainingDevice:(id)arg1;
@property(readonly, copy) NSArray *availableDevicePairs;
@property(readonly, copy) NSArray *devicePairs;
@property(readonly, copy) NSDictionary *devicePairsByUUID;
@property(readonly, copy) NSArray *availableDevices;
@property(readonly, copy) NSArray *devices;
@property(readonly, copy) NSDictionary *devicesByUDID;
- (id)description;
- (void)saveToDisk;
- (void)processDeviceSetPlist;
- (id)initWithSetPath:(id)arg1 serviceContext:(id)arg2;
- (id)init;
- (BOOL)subscribeToNotificationsWithError:(id *)arg1;

@end

@interface SimProfilesPathMonitor : NSObject
{
    NSObject<OS_dispatch_queue> *_monitorQueue;
    NSMutableArray *_leafMonitorSources;
    NSMutableDictionary *_monitoredPaths;
}

+ (id)sharedProfilesPathMonitor;
@property(retain) NSMutableDictionary *monitoredPaths; // @synthesize monitoredPaths=_monitoredPaths;
@property(retain) NSMutableArray *leafMonitorSources; // @synthesize leafMonitorSources=_leafMonitorSources;
@property(retain) NSObject<OS_dispatch_queue> *monitorQueue; // @synthesize monitorQueue=_monitorQueue;
- (void)_monitorProfilesSubDirectory:(int)arg1 path:(id)arg2 updateBlock:(CDUnknownBlockType)arg3;
- (void)_monitorProfilesDirectory:(int)arg1 path:(id)arg2 forSubDirectory:(id)arg3 updateBlock:(CDUnknownBlockType)arg4;
- (void)_monitorProfilesDirectory:(int)arg1 path:(id)arg2;
- (void)_monitorProfilesParentDirectory:(int)arg1 nextPathComponent:(id)arg2 path:(id)arg3;
- (void)_monitorProfilesPath:(id)arg1;
- (void)monitorProfilesPath:(id)arg1;
- (void)monitorDefaultProfilePaths;
- (id)init;

@end

@interface SimDevicePair : NSObject
{
    NSUUID *_UUID;
    SimDevice *_gizmo;
    SimDevice *_companion;
    NSString *_setPath;
    SimServiceContext *_serviceContext;
}

+ (id)SimDevicePairWithUUID:(id)arg1 gizmo:(id)arg2 companion:(id)arg3 serviceContext:(id)arg4 setPath:(id)arg5;
@property(retain) SimServiceContext *serviceContext; // @synthesize serviceContext=_serviceContext;
@property(copy) NSString *setPath; // @synthesize setPath=_setPath;
@property(retain) SimDevice *companion; // @synthesize companion=_companion;
@property(retain) SimDevice *gizmo; // @synthesize gizmo=_gizmo;
@property(copy) NSUUID *UUID; // @synthesize UUID=_UUID;
- (id)newDevicePairNotification;
- (long long)compare:(id)arg1;
- (id)description;
- (void)invalidate;
- (id)initWithUUID:(id)arg1 gizmo:(id)arg2 companion:(id)arg3 serviceContext:(id)arg4 setPath:(id)arg5;
- (id)init;

@end

@interface SimRuntime : NSObject
{
    unsigned int _version;
    unsigned int _minHostVersion;
    unsigned int _maxHostVersion;
    unsigned int _minCoreSimulatorFrameworkVersion;
    unsigned int _maxCoreSimulatorFrameworkVersion;
    NSString *_name;
    NSString *_identifier;
    NSBundle *_bundle;
    NSString *_root;
    NSString *_versionString;
    NSString *_buildVersionString;
    NSDictionary *_supportedFeatures;
    NSDictionary *_supportedFeaturesConditionalOnDeviceType;
    NSDictionary *_requiredHostServices;
    NSDictionary *_forwardHostNotifications;
    NSDictionary *_forwardHostNotificationsWithState;
    NSString *_platformPath;
    NSArray *_supportedProductFamilyIDs;
    NSDictionary *_environment_extra;
    void *_libLaunchHostHandle;
    NSDictionary *_aliases;
}

+ (void)supportedRuntimesAddProfilesAtPath:(id)arg1;
+ (id)supportedRuntimesByAlias;
+ (id)supportedRuntimesByIdentifier;
+ (id)supportedRuntimes;
@property unsigned int maxCoreSimulatorFrameworkVersion; // @synthesize maxCoreSimulatorFrameworkVersion=_maxCoreSimulatorFrameworkVersion;
@property unsigned int minCoreSimulatorFrameworkVersion; // @synthesize minCoreSimulatorFrameworkVersion=_minCoreSimulatorFrameworkVersion;
@property unsigned int maxHostVersion; // @synthesize maxHostVersion=_maxHostVersion;
@property unsigned int minHostVersion; // @synthesize minHostVersion=_minHostVersion;
@property(copy) NSDictionary *aliases; // @synthesize aliases=_aliases;
@property(nonatomic) void *libLaunchHostHandle; // @synthesize libLaunchHostHandle=_libLaunchHostHandle;
@property(copy) NSDictionary *environment_extra; // @synthesize environment_extra=_environment_extra;
@property(copy) NSArray *supportedProductFamilyIDs; // @synthesize supportedProductFamilyIDs=_supportedProductFamilyIDs;
@property(copy) NSString *platformPath; // @synthesize platformPath=_platformPath;
@property(copy) NSDictionary *forwardHostNotificationsWithState; // @synthesize forwardHostNotificationsWithState=_forwardHostNotificationsWithState;
@property(copy) NSDictionary *forwardHostNotifications; // @synthesize forwardHostNotifications=_forwardHostNotifications;
@property(copy) NSDictionary *requiredHostServices; // @synthesize requiredHostServices=_requiredHostServices;
@property(copy) NSDictionary *supportedFeaturesConditionalOnDeviceType; // @synthesize supportedFeaturesConditionalOnDeviceType=_supportedFeaturesConditionalOnDeviceType;
@property(copy) NSDictionary *supportedFeatures; // @synthesize supportedFeatures=_supportedFeatures;
@property unsigned int version; // @synthesize version=_version;
@property(copy) NSString *buildVersionString; // @synthesize buildVersionString=_buildVersionString;
@property(copy) NSString *versionString; // @synthesize versionString=_versionString;
@property(copy) NSString *root; // @synthesize root=_root;
@property(retain) NSBundle *bundle; // @synthesize bundle=_bundle;
@property(copy) NSString *identifier; // @synthesize identifier=_identifier;
@property(copy) NSString *name; // @synthesize name=_name;
- (id)platformRuntimeOverlay;
- (CDUnknownFunctionPointerType)launch_sim_set_death_handler;
- (CDUnknownFunctionPointerType)launch_sim_waitpid;
- (CDUnknownFunctionPointerType)launch_sim_spawn;
- (CDUnknownFunctionPointerType)launch_sim_getenv;
- (CDUnknownFunctionPointerType)launch_sim_bind_session_to_port;
- (CDUnknownFunctionPointerType)launch_sim_find_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_unregister_endpoint;
- (CDUnknownFunctionPointerType)launch_sim_register_endpoint;
- (BOOL)isAvailableWithError:(id *)arg1;
@property(readonly) BOOL available;
- (id)dyld_simPath;
- (BOOL)createInitialContentPath:(id)arg1 error:(id *)arg2;
- (id)sampleContentPath;
- (long long)compare:(id)arg1;
- (BOOL)supportsFeatureConditionally:(id)arg1;
- (BOOL)supportsFeature:(id)arg1;
- (BOOL)supportsDeviceType:(id)arg1;
- (id)environment;
- (id)description;
- (id)initWithBundle:(id)arg1;
- (id)initWithPath:(id)arg1;
- (id)init;

@end

@interface NSString (cputype)
+ (id)stringForCPUType:(int)arg1;
- (int)cputype;
@end

@interface NSArray (argv)
- (void)freeArgv:(char **)arg1;
- (char **)argv;
@end

@interface NSDictionary (envp)
- (void)freeEnvp:(char **)arg1;
- (char **)envp;
@end

@interface NSUserDefaults (SimDefaults)
+ (id)simulatorDefaults;
@end

@interface NSError (SimError)
+ (id)errorFromXPCDict:(id)arg1;
+ (id)errorWithLaunchdError:(int)arg1 userInfo:(id)arg2;
+ (id)errorWithLaunchdError:(int)arg1 localizedDescription:(id)arg2;
+ (id)errorWithLaunchdError:(int)arg1;
+ (id)errorWithSimErrno:(int)arg1 localizedDescription:(id)arg2;
+ (id)errorWithSimErrno:(int)arg1 userInfo:(id)arg2;
+ (id)errorWithSimErrno:(int)arg1;
- (id)xpcDict;
@end

