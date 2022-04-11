//
//  TTGCSocialPlatformProvider.h
//  AmuseGameSDK
//
//  Created by Balalaika on 2020/2/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmuseGameSDK/TTGCConfig.h>


NS_ASSUME_NONNULL_BEGIN

@protocol TTGCSocialPlatformProvider <NSObject>

@optional

/**
 *  Initialization platform
 *
 *  @param launchOptions       AppKey for third-party platforms
 */
- (BOOL)sosaSocial_application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  Setting platform appkey
 *
 *  @param appKey       appKey for third-party platforms
 *  @param appSecret    appSecret for third-party platforms
 *  @param redirectURL  redirectURL
 */
- (BOOL)sosaSocial_setAppKey:(NSString *)appKey
                   appSecret:(NSString *)appSecret
                 redirectURL:(NSString *)redirectURL;

/**
 *  Authorize
 *
 *  @param userInfo          Customized data for user authorization
 *  @param completionHandler Callback after authorization
 *  @discuss userInfo        In some platforms it can be brought in, if not it passes into nil.
 */
-(void)sosaSocial_AuthorizeWithUserInfo:(NSDictionary *)userInfo
                withCompletionHandler:(TTGCSocialPlateLoginCompletionHandler)completionHandler;

/**
 *  De-authorization
 *
 *  @param completionHandler Callback after deauthorization
 *  @discuss userInfo        In some platforms it can be brought in, if not it passes into nil.
 */
-(void)sosaSocial_cancelAuthWithCompletionHandler:(TTGCSocialPlateLogoutCompletionHandler)completionHandler;


/**
 *  Setting share platform
 *
 *  @param messageObject  share content @see TTGCMessageObject
 *  @param completion     callback
 */
- (void)sosaSocial_shareMessageObject:(TTGCSocialMessageObject *)messageObject
                           completion:(TTGCShareCompleteHandler)completion;


/**
 *  Get callback from sso or web to this app
 *
 *  @param url               The URL of the callback of the third-party SDK to open this app
 *  @param sourceApplication Callback source application
 *  @param annotation        annotation
 *
 *  @return  YES Success，NO Not deal with
 *
 */
- (BOOL)sosaSocial_application:(UIApplication *)application OpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
- (BOOL)sosaSocial_application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

//General (standby)
- (BOOL)sosaSocial_handleOpenURL:(NSURL *)url options:(NSDictionary*)options;

#pragma mark - Universal Link
- (BOOL)sosa_application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

/**
 *  Platform installed or not
 *
 *  @return YES installed，NO uninstalled
 */
- (BOOL)sosaSocial_isInstall;

/**
 *  Current platform support sharing
 *
 *  @return YES support，NO unsupported
 */
- (BOOL)sosaSocial_isSupport;

/**
 *  Whether the platform token is valid
 *
 *  @return YES valid，NO invalid
*/
- (BOOL)sosaSocial_isCurrentAccessTokenActive;

#pragma mark - Facebook unique
/**
 *  Show Facebook friends and send game invitations.
 *
 *  @param messageObject  message content @see TTGCMessageObject
 *  @param completion     callback
 *
*/
- (void)sosaSocial_showFBFriendsSendInvitations:(TTGCSocialMessageObject *)messageObject
                                     completion:(TTGCShareCompleteHandler)completion;

#pragma mark - GA unique

- (void)sosaLog_eventShareWithTarget:(NSString *)target shareType:(NSString *)type;

- (void)sosaLog_eventLogin;
- (void)sosa_setAnalyticsUser;

- (void)sosaLog_eventPInfoValue:(NSNumber *)value currency:(NSString *)currency type:(NSString *)type;

#pragma mark - AppsFlyer unique

- (void)sosaTraker_event:(NSString *)eventName withValues:(NSDictionary * _Nullable)values;


@end

NS_ASSUME_NONNULL_END
