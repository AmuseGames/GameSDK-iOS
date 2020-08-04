//
//  TTGCMessageModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/5.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCMessageModel : NSObject

@property (nonatomic, copy) NSString *ttkUid; // User ID of a friends or group ID
@property (nonatomic, copy) NSString *templateId; // Template of message ID
@property (nonatomic, copy) NSString *message;// Content of message TODO

@end

NS_ASSUME_NONNULL_END
