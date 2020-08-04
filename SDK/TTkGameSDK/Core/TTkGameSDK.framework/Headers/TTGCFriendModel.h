//
//  TTGCFriendModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/16.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCFriendModel : NSObject

@property (nonatomic, copy) NSString *ttkUid; //ttk uid，or groupid eg. 802..
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *photoUrl;

@end

@interface TTGCBotimFriendModel : NSObject

@property (nonatomic, copy) NSString *bimUid; //botim uid
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *photoUrl;

@end

NS_ASSUME_NONNULL_END
