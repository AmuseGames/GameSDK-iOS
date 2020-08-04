//
//  TTGCAppVersion.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/3/22.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCAppVersionModel : NSObject

@property (nonatomic, copy) NSString *build; // app new build code
@property (nonatomic, copy) NSString *version; // app new version
@property (nonatomic, copy) NSString *versionInfo; // the new version information
@property (nonatomic) BOOL forceUpdate; //need to force upgrade

@property (nonatomic, copy) NSString *currentVersionCode; // current version code

@end

NS_ASSUME_NONNULL_END
