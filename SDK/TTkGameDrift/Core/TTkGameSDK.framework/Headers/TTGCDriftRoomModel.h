//
//  TTGCDriftRoomModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/8/25.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCDriftRoomModel : NSObject

@property (nonatomic, assign) BOOL over;

@property (nonatomic, copy) NSString *roomId;
@property (nonatomic, copy) NSString *createTime;
@property (nonatomic, copy) NSString *homeowner;
@property (nonatomic, copy) NSString *state;
@property (nonatomic, copy) NSString *timing;
@property (nonatomic, copy) NSArray *userList;

@end

@interface TTGCDriftRoomUserModel : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *usedCar;
@property (nonatomic, copy) NSString *photoUrl;
@property (nonatomic, copy) NSString *nickName;
@property (nonatomic, copy) NSString *matchesNum;
@property (nonatomic, copy) NSString *matchesCount;
@property (nonatomic, copy) NSString *highScore;

@property (nonatomic, copy) NSString *score;
@property (nonatomic, copy) NSString *state;

@end

NS_ASSUME_NONNULL_END
