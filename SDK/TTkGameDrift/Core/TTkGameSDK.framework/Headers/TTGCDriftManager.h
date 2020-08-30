//
//  TTGCDriftManager.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/8/24.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "TTGCDriftUserInfoModel.h"
#import "TTGCDriftRoomModel.h"
#import "TTGCDriftFriendsModel.h"

#import "TTGCDriftFriendsRankModel.h"
#import "TTGCDriftAllRankModel.h"


NS_ASSUME_NONNULL_BEGIN

@interface TTGCDriftManager : NSObject

typedef NS_ENUM(NSInteger, TTGCDriftErrorType) {
    TTGCDriftErrorType_Unknow              = 3000,             // unknow error
    
};

#pragma mark - CompletionHandler

/**
 *  Common result callback
 *
 *  @param result common result
 *  @param error error message
 */
typedef void (^TTGCDriftDataCompletionHandler)(id _Nullable result, NSError *_Nullable error);

/**
 *  Invite Room info
 *
 *  @param roomid room id
 *  @param error error message
 */
typedef void (^TTGCDriftInviteRoomCompletionHandler)(id _Nullable roomid, NSError *_Nullable error);

/**
 *
 *  @param success upload success
 *  @param error error message
 */
typedef void (^TTGCDriftUploadCompletionHandler)(BOOL success, NSError *_Nullable error);

/**
 *
 *  @param success upload success
 *  @param error error message
 */
typedef void (^TTGCDriftCompletionHandler)(BOOL success, NSError *_Nullable error);

/**
 *  User info callback
 *
 *  @param user user model
 *  @param error error message
 */
typedef void (^TTGCDriftUserInfoCompletionHandler)(id _Nullable user, NSError *_Nullable error);

/**
 *  Friends callback
 *
 *  @param list friends list
 *  @param error error message
 */
typedef void (^TTGCDriftFriendsListCompletionHandler)(id _Nullable list, NSError *_Nullable error);

/**
 *  Room info callback
 *
 *  @param room room info model
 *  @param error error message
 */
typedef void (^TTGCDriftRoomCompletionHandler)(id _Nullable room, NSError *_Nullable error);

/**
 *  Room List callback
 *
 *  @param room room info list
 *  @param error error message
 */
typedef void (^TTGCDriftRoomListCompletionHandler)(id _Nullable roomList, NSError *_Nullable error);



#pragma mark - Drift Data
@property (nonatomic, strong) TTGCDriftUserInfoModel *userModel;
@property (nonatomic, strong) TTGCDriftRoomModel *roomModel;

@property (nonatomic, copy) NSString *roomInviteTitle;
@property (nonatomic, copy) NSString *roomInviteDescription;
@property (nonatomic, copy) NSString *roomInviteImageUrl;

+ (instancetype)defaultManager;


- (void)uploadCarInfo:(NSString *)car completion:(TTGCDriftUploadCompletionHandler)completion;

- (void)getUserInfo:(TTGCDriftUserInfoCompletionHandler)completion;

- (void)getInvitationList:(TTGCDriftRoomListCompletionHandler)completion;

- (void)getPlayingFriends:(TTGCDriftFriendsListCompletionHandler)completion;

- (void)createRoomWithUsers:(NSArray *)users completion:(TTGCDriftRoomCompletionHandler)completion;

- (void)getRoomInfoInWaiting:(TTGCDriftRoomCompletionHandler)completion;

- (void)getRoomInfoEndGame:(TTGCDriftRoomCompletionHandler)completion;

- (void)getGameInviteMessage:(TTGCDriftInviteRoomCompletionHandler)completion;

- (void)startGame:(TTGCDriftRoomCompletionHandler)completion;

- (void)updateScore:(NSString *)score completion:(TTGCDriftRoomCompletionHandler)completion;

- (void)endGameScore:(NSString *)score completion:(TTGCDriftRoomCompletionHandler)completion;

// 非正常游戏逻辑 离开房间
- (void)closeRoom;

- (void)acceptGameInviteRoom:(NSString *)roomid completion:(TTGCDriftCompletionHandler)completion;

- (void)refuseGameInviteRoom:(NSString *)roomid completion:(TTGCDriftCompletionHandler)completion;

- (void)friendsRank:(TTGCDriftDataCompletionHandler)completion;

- (void)allRank:(TTGCDriftDataCompletionHandler)completion;

- (BOOL)ttgc_driftApplication:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;

@end

NS_ASSUME_NONNULL_END
