//
//  TTGCConfig.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/1.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TTGCUserModel.h"
#import "TTGCFriendModel.h"
#import "TTGCPlayingFriendModel.h"
#import "TTGCOrderModel.h"
#import "TTGCSocialMessageObject.h"
#import "TTGCAppVersionModel.h"

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
