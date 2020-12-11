//
//  TTGCConfig.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/1.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TTkGameSDK/TTGCUserModel.h>
#import <TTkGameSDK/TTGCFriendModel.h>
#import <TTkGameSDK/TTGCPlayingFriendModel.h>
#import <TTkGameSDK/TTGCOrderModel.h>
#import <TTkGameSDK/TTGCSocialMessageObject.h>
#import <TTkGameSDK/TTGCAppVersionModel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  pay progress status enum
 */
typedef NS_ENUM(NSInteger, TTGCOderStatus) {
    TTGCOrderStatus_ProductQuerying          = 1, // order querying
    TTGCOrderStatus_Generating               = 2, // order init
    TTGCOrderStatus_ProductPurchasing        = 3, // order in trading progress
    TTGCOrderStatus_ProductPurchased         = 4, // order purchased
    TTGCOrderStatus_ReceiptChecking          = 5, // order verifying
};

/**
 *  track event enum
 */
typedef NS_ENUM(NSInteger, TTGCTrackEvent) {
    TTGCTrackEvent_Activity          = 1,  // activity event
    TTGCTrackEvent_Guide             = 2,  // guide event
    TTGCTrackEvent_GuideCompletion   = 3,  // guide completion
    TTGCTrackEvent_Reward            = 4,  // reward event
    TTGCTrackEvent_Rank              = 5,  // rank event
    TTGCTrackEvent_VipInfo           = 6,  // vip info event
    TTGCTrackEvent_AdClick           = 7,  // ad click event
    TTGCTrackEvent_Launch            = 8,  // ad launch event
    TTGCTrackEvent_Login             = 9,  // ad login event
    TTGCTrackEvent_Purchase          = 10, // ad purchase event
    TTGCTrackEvent_Other             = 11, // other event
};

/**
 *  track event param keys
 */
#define TTGCTrackParamLaunchFirst            @"af_launch_first"
#define TTGCTrackParamUserUid                @"af_user_uid"
#define TTGCTrackParamUserType               @"af_user_type"
#define TTGCTrackParamActivityId             @"af_activity_id"
#define TTGCTrackParamActivityAction         @"af_activity_action"

#define TTGCTrackParamGuideId                @"af_tutorial_id"
#define TTGCTrackParamGuideSuccess           @"af_success"
#define TTGCTrackParamGuideDetail            @"af_tutorial_detail"

#define TTGCTrackParamRewardId               @"af_reward_id"
#define TTGCTrackParamUserVip                @"af_user_vip"
#define TTGCTrackParamAdId                   @"af_ad_id"


/**
 *  The launch animation finished callback
 *
 *  @param isFinish the animation finished
 *
 */
typedef void (^TTGCLaunchCompletion)(BOOL isFinish);

/**
 *  Login action
 *
 *  @param actionType the action type
 *
 */
typedef void (^TTGCLoginAction)(TTGCLoginType actionType);

/**
 *  Login callback
 *
 *  @param userInfo user detail information. model class <TTGCUserModel>
 *  @param error error message
 */
typedef void (^TTGCUserCompletionHandler)(id _Nullable userInfo, NSError *_Nullable error);

/**
 *  Social platform authorization callback
 *
 *  @param loginResult platform authorization information. result class <NSDictionary>
 *  @param error error message
 */
typedef void (^TTGCSocialPlateLoginCompletionHandler)(id _Nullable loginResult, NSError *_Nullable error);

/**
 *  Social platform cancels the authorization operation callback
 *
 *  @param logoutResult unauthorization infomation. result class <NSDictionary>
 *  @param error error message
 */
typedef void (^TTGCSocialPlateLogoutCompletionHandler)(id _Nullable logoutResult, NSError *_Nullable error);

/**
 *  Recieve notification callbackd
 *
 *  @param result notification result
 *  @param error error message
 */
typedef void (^TTGCNotificationCompletionHandler)(id _Nullable result, NSError *_Nullable error);

/**
 *  Using the system album select photos callback
 *
 *  @param mediaInfo selected media information. result class <NSDictionary>
 *  mediaInfo:
 *   keys            values
 *  MediaType       <NSString>   eg. Photo：public.image  Video：public.movie
 *  ImageURL        <NSURL>
 *  OriginalImage   <UIImage>
 *  ReferenceURL    <NSURL>      an NSURL that references an asset
 *
 *  @param error error message
 */
typedef void (^TTGCSocialSystemPhotoCompletionHandler)(id _Nullable mediaInfo, NSError *_Nullable error);

/**
 *  Logout callback
 *
 *  @param success <BOOL>
 *  @param error error message
 */
typedef void (^TTGCLogoutCompleteHandler)(BOOL success, NSError *_Nullable error);

/**
 *  Account Kicked Notification
 *
 *  @param information notification message
 */
typedef void (^TTGCAccountKickedHandler)(NSString *_Nullable information);

/**
 *  Account Banned Notification
 *
 *  @param information reason message
 *  @param time banned time （timestamp）
 */
typedef void (^TTGCAccountBannedHandler)(NSString *_Nullable information, NSString *_Nullable time);

/**
 *  TTk Friends list callback
 *
 *  @param list <NSArray>
 *  @param error error message
 */
typedef void (^TTGCTTkFriendsCompletionHandler)(id _Nullable list, NSError *_Nullable error);

/**
 *  Botim Friends list callback
 *
 *  @param list <NSArray>
 *  @param error error message
 */
typedef void (^TTGCBimFriendsCompletionHandler)(id _Nullable list, NSError *_Nullable error);

/**
 *  Share callback
 *
 *  @param success <BOOL>
 *  @param error error message
 */
typedef void (^TTGCShareCompleteHandler)(BOOL success, NSError *_Nullable error);

/**
 *  Universal Link Handle
 *
 *  @param url url of link
 *  @param error error message
 */
typedef void (^TTGCUniversalLinkHandler)(NSURL *url, NSError *_Nullable error);

/**
 *  Pay progress status callback
 *
 *  @param orderStatus <NS_ENUM>
 */
typedef void (^TTGCOrderProgressHandler)(TTGCOderStatus orderStatus);

/**
 *  Pay result callback
 *
 *  @param orderInfo order detail information
 *  @param error error message
 */
typedef void (^TTGCOrderCompletionHandler)(id _Nullable orderInfo, NSError *_Nullable error);

/**
 *  Product detail callback
 *
 *  @param productInfo product detail information
 *  @param error error message
 */
typedef void (^TTGCProductCompletionHandler)(id _Nullable productInfo, NSError *_Nullable error);

/**
 *  Get version info callback
 *
 *  @param hasNewVersion has new version
 *  @param versionInfo the version detail information. class model <TTGCAppVersion>
 *  @param error error message
 */
typedef void (^TTGCVersionCompletionHandler)(BOOL hasNewVersion, TTGCAppVersionModel *_Nullable versionInfo, NSError *_Nullable error);

/**
 *  Common result callback
 *
 *  @param result common result
 *  @param error error message
 */
typedef void (^TTGCCompletionHandler)(id _Nullable result, NSError *_Nullable error);


/////////////////////////////////////////////////////////////////////////////
//Platform error code --start
/////////////////////////////////////////////////////////////////////////////
/**
 *  Error Type
 */
typedef NS_ENUM(NSInteger, TTGCPlatformErrorType) {
    TTGCPlatformErrorType_Unknow              = 2000,             // unknow error
    TTGCPlatformErrorType_AuthorizeFailed     = 2001,             // authorization failed
    TTGCPlatformErrorType_ForUserInfoFailed   = 2002,             // get user information failed
    TTGCPlatformErrorType_LoginFailed         = 2003,             // login failed
    TTGCPlatformErrorType_FriendsListFailed   = 2004,             // get friends list failed
    TTGCPlatformErrorType_MessageSendFailed   = 2005,             // send message failed
    TTGCPlatformErrorType_PayFailed           = 2006,             // pay failed
    TTGCPlatformErrorType_ShareFailed         = 2007,             // share failed
    TTGCPlatformErrorType_NotInstall          = 2008,             // the application uninstall
    TTGCPlatformErrorType_NotNetWork          = 2009,             // net work error
    TTGCPlatformErrorType_SourceError         = 2010,             // third error
    TTGCPlatformErrorType_NoPermission        = 2011,             // no permissions
    TTGCPlatformErrorType_UnauthorizedRequest = 2012,             // unauthorized request, need login.
};

/** The domain name used for the TTGCPlatformErrorType */
extern NSString* const TTGCPlatformErrorDomain;

/////////////////////////////////////////////////////////////////////////////
//Platform error code --end
/////////////////////////////////////////////////////////////////////////////


@interface TTGCConfig : NSObject

/**
 *  Create an error object
 *
 *  @param errorType Error type
 *  @param userInfo  Customized error message
 *
 *  @return   Returns an object of type NSError
 */
+ (NSError *)errorWithTTGCErrorType:(TTGCPlatformErrorType)errorType userInfo:(id)userInfo;

@end


NS_ASSUME_NONNULL_END
