//
//  TTGCDriftFriendsModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/8/25.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCDriftFriendsModel : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *thirdUid;
@property (nonatomic, copy) NSString *usedCar;
@property (nonatomic, copy) NSString *photoUrl;
@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *matchesNum;
@property (nonatomic, copy) NSString *matchesCount;
@property (nonatomic, copy) NSString *highScore;

@end

NS_ASSUME_NONNULL_END
