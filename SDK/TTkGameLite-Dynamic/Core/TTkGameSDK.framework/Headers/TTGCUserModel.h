//
//  TTGCUserModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/16.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  User Type
 */
typedef NS_ENUM(NSInteger, TTGCLoginType) {
    TTGCLoginType_unloggedIn       = 0,             // unlogin
    TTGCLoginType_TTk              = 1,             // TTk user
    TTGCLoginType_GameCenter       = 2,             // GameCenter user
    TTGCLoginType_Facebook         = 3,             // Facebook user
    TTGCLoginType_Guest            = 4,             // Guest user
    TTGCLoginType_Apple            = 5,             // Apple user
    TTGCLoginType_Twitter          = 6,             // Twitter user
    TTGCLoginType_Botim            = 7,             // Botim user
};

NS_ASSUME_NONNULL_BEGIN

@interface TTGCUserModel : NSObject

@property (nonatomic) TTGCLoginType userType; //user type
@property (nonatomic, copy) NSString *userId; //TTkGame userid
@property (nonatomic, copy) NSString *thirdUid; //third-party uid
@property (nonatomic, copy) NSString *accessToken; //TTkGame authorization token
@property (nonatomic, copy) NSString *nickname; //nick name
@property (nonatomic, copy) NSString *photoUrl; //photo

@end

NS_ASSUME_NONNULL_END
