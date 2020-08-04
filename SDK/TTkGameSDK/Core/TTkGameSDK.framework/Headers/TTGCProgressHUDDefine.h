//
//  Created by Balalaika on 2020/1/18.
//  Copyright © 2020 GMCT. All rights reserved.
//

#define IOS6 [[[UIDevice currentDevice] systemVersion] floatValue] < 7.0
#define IOS7 [[[UIDevice currentDevice] systemVersion] floatValue] < 8.0

#define MAXFLOAT    0x1.fffffep+127f

#import "TTGCProgressHUD.h"

#pragma mark - TTGCProgressHUD

/**
 *  TTGCHUD default setting
 *
 */
#define SETUP_TTGCHUD   {\
[TTGCProgressHUD setMinimumDismissTimeInterval:1.5];\
[TTGCProgressHUD setDefaultStyle:TTGCProgressHUDStyleCustom];\
[TTGCProgressHUD setBackgroundColor:[UIColor groupTableViewBackgroundColor]];\
[TTGCProgressHUD setDefaultMaskType:TTGCProgressHUDMaskTypeClear];\
}

/**
 *  TTGCHUD show (Hidden by default)
 *
 */
#define TTGCHUD_Normal(meg)   {\
[TTGCProgressHUD showWithStatus:meg];\
[TTGCProgressHUD dismissAfterDelay:1.5];\
}

/**
 *  TTGCHUD show (Not hidden by default)
 *
 */
#define TTGCHUD_NO_Stop(meg) {\
[TTGCProgressHUD showWithStatus:meg];\
}

/**
 *  TTGCHUD hide
 *
 */
#define TTGCHUD_Stop dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD dismiss];});

/**
 *  TTGCHUD request failed
 */
#define TTGCHUD_HTTP_ERROR(msg) dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD showErrorWithStatus:msg?msg:@"Faild"];});

/**
 *  TTGCHUD request success
 */
#define TTGCHUD_HTTP_SUCCESS(msg) dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD showSuccessWithStatus:msg?msg:@"Success"];});

/**
 *  TTGCHUD tips
 */
#define TTGCHUD_HINT(msg) dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD showInfoWithStatus:msg];});

/**
 *  TTGCHUD error message
 */
#define TTGCHUD_ERROR(msg) dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD showErrorWithStatus:msg];});

/**
 *  TTGCHUD success message
 */
#define TTGCHUD_SUCCESS(msg) dispatch_async(dispatch_get_main_queue(), ^{[TTGCProgressHUD showSuccessWithStatus:msg];});

