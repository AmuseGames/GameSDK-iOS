//
//  TTGCOrderModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/2/16.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCOrderModel : NSObject


@property (nonatomic, copy) NSString *orderId; //order id
@property (nonatomic, copy) NSString *orderRef; //pay-third orderid

@property (nonatomic, copy) NSString *channel; //pay channel  0: apple，1: google, 2: ttk
@property (nonatomic, copy) NSString *env; //pay environment  0: sandbox，1: production
@property (nonatomic, copy) NSString *sku;
@property (nonatomic, copy) NSString *amount;

@property (nonatomic, copy) NSString *createTime;
@property (nonatomic, copy) NSString *payTime;
@property (nonatomic, copy) NSString *cancelTime;

@property (nonatomic, copy) NSString *status; // 1: success, 2: failure


@end


@interface TTGCProductModel : NSObject

@property (nonatomic, copy) NSString *sku; //The string that identifies the product to the Apple App Store.
@property (nonatomic, copy) NSString *price; //The cost of the product in the local currency.
@property (nonatomic, copy) NSString *localeCurrency; //The currency code associated with the locale.
@property (nonatomic, copy) NSString *localizedTitle; //The name of the product.
@property (nonatomic, copy) NSString *localizedDescription; //A description of the product.

@end

NS_ASSUME_NONNULL_END
