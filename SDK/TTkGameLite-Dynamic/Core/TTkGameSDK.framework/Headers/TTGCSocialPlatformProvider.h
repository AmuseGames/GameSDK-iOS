//
//  TTGCSocialPlatformProvider.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTGCConfig.h"


NS_ASSUME_NONNULL_BEGIN

@protocol TTGCSocialPlatformProvider <NSObject>

@optional

/**
 *  Initialization platform
 *
 *  @param launchOptions       AppKey for third-party platforms
 */
- (BOOL)ttgcSocial_application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 *  Setting platform appkey
 *
 *  @param appKey       appKey for third-party platforms
 *  @param appSecret    appSecret for third-party platforms
 *  @param redirectURL  redirectURL
 */
- (BOOL)ttgcSocial_setAppKey:(NSString *)appKey
                   appSecret:(NSString *)appSecret
                 redirectURL:(NSString *)redirectURL;

/**
 *  Authorize
 *
 *  @param userInfo          Customized data for user authorization
 *  @param completionHandler Callback after authorization
 *  @discuss userInfo        In some platforms it can be brought in, if not it passes into nil.
 */
-(void)ttgcSocial_AuthorizeWithUserInfo:(NSDictionary *)userInfo
                withCompletionHandler:(TTGCSocialPlateLoginCompletionHandler)completionHandler;

/**
 *  De-authorization
 *
 *  @param completionHandler Callback after deauthorization
 *  @discuss userInfo        In some platforms it can be brought in, if not it passes into nil.
 */
-(void)ttgcSocial_cancelAuthWithCompletionHandler:(TTGCSocialPlateLogoutCompletionHandler)completionHandler;


/**
 *  Setting share platform
 *
 *  @param messageObject  share content @see TTGCMessageObject
 *  @param completion     callback
 */
- (void)ttgcSocial_shareMessageObject:(TTGCSocialMessageObject *)messageObject
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
- (BOOL)ttgcSocial_application:(UIApplication *)application OpenURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
- (BOOL)ttgcSocial_application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

//General (standby)
- (BOOL)ttgcSocial_handleOpenURL:(NSURL *)url options:(NSDictionary*)options;

#pragma mark - Universal Link
- (BOOL)ttgc_application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

/**
 *  Platform installed or not
 *
 *  @return YES installed，NO uninstalled
 */
- (BOOL)ttgcSocial_isInstall;

/**
 *  Current platform support sharing
 *
 *  @return YES support，NO unsupported
 */
- (BOOL)ttgcSocial_isSupport;

/**
 *  Whether the platform token is valid
 *
 *  @return YES valid，NO invalid
*/
- (BOOL)ttgcSocial_isCurrentAccessTokenActive;

#pragma mark - Facebook unique
/**
 *  Show Facebook friends and send game invitations.
 *
 *  @param messageObject  message content @see TTGCMessageObject
 *  @param completion     callback
 *
*/
- (void)ttgcSocial_showFBFriendsSendInvitations:(TTGCSocialMessageObject *)messageObject
                                     completion:(TTGCShareCompleteHandler)completion;

#pragma mark - GA unique

- (void)ttgcLog_eventShareWithTarget:(NSString *)target shareType:(NSString *)type;

- (void)ttgcLog_eventLogin;
- (void)ttgc_setAnalyticsUser;

- (void)ttgcLog_eventPaymentInfoValue:(NSNumber *)value currency:(NSString *)currency payType:(NSString *)type;


@end

NS_ASSUME_NONNULL_END
