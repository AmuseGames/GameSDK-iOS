//
//  TTkGameManager.h
//  AmuseGameSDK
//
//  Created by Balalaika on 2020/1/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AmuseGameSDK/TTGCConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTkGameManager : NSObject

+ (instancetype)defaultManager;

/**
 Initialization
 */
- (void)setupWithAppId:(NSString *)appid Secret:(NSString *)secret GameId:(NSString *)gameid Application:(UIApplication *)application Options:(NSDictionary *)launchOptions;

- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;

/**
 Launch Animation
 Start the default animation, use it selectively, and don't care if you implement it.
 */
- (void)launchAnimationCompletion:(TTGCLaunchCompletion)completion;

#pragma mark - Login

/**
 Login User Type
 */
- (TTGCLoginType)loginType;

/**
 Login User Information(Model data is only available when logged in.)
 */
- (TTGCUserModel *)loginUserModel;

/**
 AccessToken is only available when logged in.
 */
- (void)getAvailableAccessToken:(TTGCUserCompletionHandler)completion;

/**
 Botim Login
 
 @param completion login callback
 */
- (void)loginWithBotimCompletion:(TTGCUserCompletionHandler)completion;

/**
 Botim is install
*/
- (BOOL)botimIsInstall;

//login
- (void)loginWithTTkCompletion:(TTGCUserCompletionHandler)completion;

/**
 Apple Login
 
 @param completion login callback
 */
- (void)loginWithAppleCompletion:(TTGCUserCompletionHandler)completion;

/**
 Gamecenter Login
 
 @param completion login callback
 */
- (void)loginWithGameCenterCompletion:(TTGCUserCompletionHandler)completion;

/**
 Facebook Login
 
 @param completion login callback
 */
- (void)loginWithFacebookCompletion:(TTGCUserCompletionHandler)completion;

/**
 Twitter Login
 
 @param completion login callback
 */
- (void)loginWithTwitterCompletion:(TTGCUserCompletionHandler)completion;

/**
 Third-party callback（Must be implemented in AppDelegate）
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/**
 Guests Login
 
 @param completion login callback
 */
- (void)guestLoginCompletion:(TTGCUserCompletionHandler)completion;

/**
 Get User Information
 
 @param completion user information callback
 */
- (void)userInfoCompletion:(TTGCUserCompletionHandler)completion;

/**
 Logout
 
 @param completion logout reult
 */
- (void)logout:(TTGCLogoutCompleteHandler)completion;

/**
 Notification of account being kicked out
 
 @param handler notification information
 */
- (void)accountKickedNotification:(TTGCAccountKickedHandler)handler;

/**
 Notification of account being banned
 
 @param handler notification information
 */
- (void)accountBannedNotification:(TTGCAccountBannedHandler)handler;

#pragma mark - Share

/**
 *  FB share
 *
 *  @param messageObject  share content type @see TTGCSocialFBLink TTGCSocialFBImages
 *  @param completion   callback
 */
- (void)facebookShareMessage:(id)messageObject completion:(TTGCShareCompleteHandler)completion;

/**
 *  WhatsApp share
 *
 *  @param messageObject  share content type @see TTGCSocialWALink TTGCSocialWAImages
 *  @param completion   callback
 */
- (void)whatsAppShareMessage:(id)messageObject completion:(TTGCShareCompleteHandler)completion;

/**
 *  Use System Album
 *
 *  @param completion   callback
 *  callback data @TTGCSocialSystemPhotoCompletionHandler
 */
- (void)openSystemPhotoCompletion:(TTGCSocialSystemPhotoCompletionHandler)completion;

/**
*  share message
*
*  @param message  share content type @see TTGCSocialTTkInvite & TTGCSocialTTkNotice
*  @param completion   callback
*/
- (void)sendToMessageTottk:(id)message Completion:(TTGCShareCompleteHandler)completion;

/**
*  botim share
*
*  @param message  share content type @see TTGCSocialBimMessage
*  @param completion   callback
*/
- (void)sendToMessageToBotim:(id)message Completion:(TTGCShareCompleteHandler)completion;


#pragma mark - Push Notification

/**
 Recieve deviceToken（Must be implemented in AppDelegate）
 
 @param token apns return the token
 */
- (void)registerDeviceToken:(NSData *)token;

/**
 Remove all notifications
 */
- (void)cleanNotification;

/**
 Receive remote notifications
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo;

/**
 Get remote notification information
 */
- (void)getRemoteNotification:(TTGCNotificationCompletionHandler)completion;

/**
 Set whether users receive pushes
 
 @param pushOn YES:open push NO:close push
 @param handler return the setting result YES:success NO:failure
 */
- (void)settingPush:(BOOL)pushOn Result:(void(^)(BOOL success))handler;

/**
 Determine if system push is on
 
 @param handler The return value is a boolean YES:Notification turned on, NO:Notification closed
 */
- (void)checkSystemNotificationEnable:(void(^)(BOOL isOn))handler;

/**
 Open system notification settings page
 */
- (void)systemNotificationSetting;

#pragma mark - TTk消息

/**
Get friends list from server

@param completion friends list callback
*/
- (void)getFriendsFromServerCompletion:(TTGCTTkFriendsCompletionHandler)completion;

/**
Get playing friends list from server

@param completion friends list callback
*/
- (void)getPlayingFriendsFromServerCompletion:(TTGCTTkFriendsCompletionHandler)completion;


#pragma mark - Botim

/**
 Get botim friends list from server
 
 @param completion friends list callback
 */
- (void)getFriendsFromBotimCompletion:(TTGCBimFriendsCompletionHandler)completion;

/**
 Get botim playing friends list from server
 
 @param completion friends list callback
 */
- (void)getPlayingFriendsFromBotimCompletion:(TTGCBimFriendsCompletionHandler)completion;


#pragma mark - Pay

/**
 Product
 
 @param sku goods ID
 @param completion product detail completion callback
 */
- (void)getProductDetailWithSKU:(NSString *)sku Completion:(TTGCProductCompletionHandler)completion;

/**
 Purchase (The following new method with name parameter is recommended.)
 
 @param sku goods ID
 @param progress Purchase process callback
 @param completion Purchase completion callback
 */
- (void)buyProductWithSKU:(NSString *)sku Progress:(TTGCOrderProgressHandler)progress Completion:(TTGCOrderCompletionHandler)completion;

/**
 Purchase (recommended)
 
 @param sku goods ID
 @param name goods name
 @param progress Purchase process callback
 @param completion Purchase completion callback
 */
- (void)buyProductWithSKU:(NSString *)sku WithName:(NSString *)name Progress:(TTGCOrderProgressHandler)progress Completion:(TTGCOrderCompletionHandler)completion;

/**
 Purchase (xsl-pay)
 
 @param sku goods ID
 @param currency pay currency
 @param completion Purchase completion callback
 */
- (void)xslBuyProductWithSKU:(NSString *)sku Currency:(NSString *)currency Completion:(TTGCOrderCompletionHandler)completion;

/**
 Checking Order
 
 @param orderID order id
 @param completion search result, callback to return order information
 */
- (void)queryOrderWithOrderId:(NSString *)orderID Completion:(TTGCOrderCompletionHandler)completion;

#pragma mark - Configuration information

/**
 Get User Agreement URL
 */
- (NSString *)getAgreementUrlString;

/**
 Open Agreement View
 */
- (void)showAgreementView;


#pragma mark - SDK Configuration

#pragma - Configure the domain
/**
 Switch SDK server environment
 */
- (void)setServerDomainTest;//test environment
- (void)setServerDomainProduction;//production environment
- (void)setSDKServerDomain:(NSString *)domain;
- (void)setSDKDevelopServerDomain:(NSString *)domain;

/**
 Get the current SDK server domain
 */
- (NSString *)SDKServerDomain;

#pragma - Log Information
/**
 Log information output. open & close
 */
- (void)openLogInfo;
- (void)closeLogInfo;

#pragma - Payment Environment
/**
 Switch payment environment
 */
- (void)setPayEnvironmentTest;//test environment
- (void)setPayEnvironmentProduction;//production environment
- (int)getPayEnvironment;//1 production   2 test

#pragma mark - App Update
/**
 Get app version info
 
 @param completion version info callback
 */
- (void)checkAppVersionCompletion:(TTGCVersionCompletionHandler)completion;

/**
 Open appstore show details of app.
 
 @param identifier App Store item identifier (NSNumber) of the product
 */
- (void)openAppStoreWithStoreIdentifier:(NSString *)identifier;

#pragma mark - Universal Link

- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

#pragma mark - af track

/**
Track

@param event track event type (TTGCTrackEvent)
@param values event params
*/
- (void)tracker_event:(TTGCTrackEvent)event withValues:(NSDictionary * _Nullable)values;

/**
 Contact us
 
 Contact us with messenger app.
*/
- (void)contactusWithMessenger;

@end

NS_ASSUME_NONNULL_END
