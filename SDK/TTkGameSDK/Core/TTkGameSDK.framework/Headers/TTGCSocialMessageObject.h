//
//  TTGCSocialMessageObject.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/21.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

/**
 *  Social platform type
 */
typedef NS_ENUM(NSInteger, TTGCSocialPlateType) {
    TTGCSocialPlate_Facebook       = 1,             // Facebook
    TTGCSocialPlate_WhatsApp       = 2,             // WhatsApp
    
    //The following content is not open yet
    TTGCSocialPlate_Messenger      = 3,             // Messenger
    TTGCSocialPlate_TTkApp         = 4,             // TTkApp
    TTGCSocialPlate_TTkApi         = 5,             // TTkApi
    TTGCSocialPlate_BimApp         = 6,             // BimApp
    TTGCSocialPlate_BimApi         = 7              // BimApi
};

/**
 *  Share content type
 */
typedef NS_ENUM(NSInteger, TTGCShareContentType) {
    TTGCShareContent_Link          = 1,
    TTGCShareContent_FBGameInvite  = 2,
    TTGCShareContent_Photo         = 3,
    
    //The following content is not open yet
    TTGCShareContent_Video         = 4,
    TTGCShareContent_Media         = 5,
};

/**
 *  Share custom templates
 */
typedef NS_ENUM(NSInteger, TTGCShareTemplate) {
    TTGCShareTemplate_Default        = 1,             // the link of game page
    TTGCShareTemplate_Invite         = 2,             // invite link
    
    //The following content is not open yet
    TTGCShareTemplate_Notice         = 3,             // notice link
    TTGCShareTemplate_Showoff        = 4,             // showoff link
};

NS_ASSUME_NONNULL_BEGIN

//TTGCSocialMessageObject
//The model is temporarily internal, so game developers do n’t need to pay attention
@interface TTGCSocialMessageObject : NSObject

/**
 Social platform type
 Share required fields
*/
@property (nonatomic) TTGCSocialPlateType plateType;

/**
 Share content type
 Share required fields
*/
@property (nonatomic) TTGCShareContentType contentType;

/**
 Share custom templates
 When the sharing content type is TTGCShareContent_Link is a required field
*/
@property (nonatomic) TTGCShareTemplate shareTemplate;

/**
 link URL
 Currently the link content is defined by the SDK based on the shareTemplate, and developers do not need to use.
*/
@property (nonatomic, copy, nullable) NSURL *contentURL;

/**
 Some quote text of the link.（Facebook）
If specified, the quote text will render with custom styling on top of the link.
*/
@property (nonatomic, copy, nullable) NSString *quote;

/**
 Share photos array
 
 Supported types
 facebook:（UIImage、NSURL、PHAsset）
 messenger: (UIImage、NSURL)
 whatsApp: (UIImage、NSURL)
*/
@property (nonatomic, copy) NSArray *photos;

/**
 Share photos array
 
 Supported types
 facebook:（UIImage、NSURL、PHAsset）
 messenger: (UIImage、NSURL)
 whatsApp: (UIImage、NSURL)
*/
@property (nonatomic, copy) UIImage *photoImage;

/**
 Video
 
 Supported types
 facebook:（NSData、PHAsset、NSURL）
 messenger: (NSURL)
 whatsApp: (NSURL)
 */
/**
 video data.
*/
@property (nonatomic, strong, nullable) NSData *videoData;

/**
 The representation of the video in the Photos library.
 @return PHAsset that represents the video in the Photos library.
*/
@property (nonatomic, copy, nullable) PHAsset *videoAsset;

/**
 The file URL to the video.
 @return URL that points to the location of the video on disk
*/
@property (nonatomic, copy, nullable) NSURL *videoURL;

/**
 Share content string
 
 Supported types
 whatsApp: (NSString)
*/
@property (nonatomic, copy) NSString *contentString;


@end

/************************* Facebook ******************************/

// FacebookInvite Model
@interface TTGCSocialFBInvite : NSObject

@property (nonatomic, copy, nullable) NSString *quote; // Some quote text of the link

@end

// FacebookGameInvite to friends Model
@interface TTGCSocialFBFriendsGameInvite : NSObject

@property (nonatomic, copy, nullable) NSString *inviteString;

@end

// Facebook Image Model
@interface TTGCSocialFBImages : NSObject

@property (nonatomic, copy) UIImage *photoImage; // share image <UIImage>

@end

/************************* WhatsApp ******************************/

// WhatsApp Link Model
@interface TTGCSocialWAInvite : NSObject

@property (nonatomic, copy) NSString *contentString; // share content string

@end

// WhatsApp Image Model
@interface TTGCSocialWAImages : NSObject

@property (nonatomic, copy) NSArray *photos; // share images array（UIImage、NSData、PHAsset、NSURL）

@end

// ttk invite model
@interface TTGCSocialTTkInvite : NSObject

@property (nonatomic, copy) NSString *ttkUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *buttonTitle;
@property (nonatomic, copy) NSString *imageUrl;

@end

// ttk notice model
@interface TTGCSocialTTkNotice : NSObject

@property (nonatomic, copy) NSString *ttkUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim invite model
@interface TTGCSocialBimInvite : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *buttonTitle;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim notice model
@interface TTGCSocialBimNotice : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *imageUrl;

@end

// botim card message model
@interface TTGCSocialBimMessage : NSObject

@property (nonatomic, copy) NSString *bimUid;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *contentString;
@property (nonatomic, copy) NSString *imageUrl;

@end


NS_ASSUME_NONNULL_END
