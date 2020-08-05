//
//  TTGCPlayingFriendModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/5/26.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCPlayingFriendModel : NSObject

@property (nonatomic, copy) NSString *userId; //ttk game userid
@property (nonatomic, copy) NSString *ttkUid; //ttk uid，or groupid eg. 802..
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *photoUrl;

@end

@interface TTGCBotimPlayingFriendModel : NSObject

@property (nonatomic, copy) NSString *userId; //ttk game userid
@property (nonatomic, copy) NSString *bimUid; //
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *photoUrl;

@end

NS_ASSUME_NONNULL_END
