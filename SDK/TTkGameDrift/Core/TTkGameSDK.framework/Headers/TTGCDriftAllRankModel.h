//
//  TTGCDriftAllRankModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/8/27.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCDriftAllRankModel : NSObject

@property (nonatomic, copy) NSString *sort; // 排名
@property (nonatomic, copy) NSString *usedCar; // 使用车辆
@property (nonatomic, copy) NSString *photoUrl; // 头像
@property (nonatomic, copy) NSString *nickName; // 昵称
@property (nonatomic, copy) NSString *matchesNum; // 参与对战次数
@property (nonatomic, copy) NSString *highScore; // 最高分

@end

NS_ASSUME_NONNULL_END
