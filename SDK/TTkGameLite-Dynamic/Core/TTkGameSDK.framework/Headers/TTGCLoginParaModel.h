//
//  TTGCLoginParaModel.h
//  TTkGameSDK
//
//  Created by Balalaika on 2020/5/28.
//  Copyright © 2020 GMCT. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TTGCLoginParaModel : NSObject

@end



/**
localPlayer information from Apple GKLocalPlayer
verification information from generateIdentityVerificationSignatureWithCompletionHandler
*/

@interface TTGCGameCenterLoginParaModel : NSObject

@property (nonatomic, copy) NSString *playerID; // localPlayer.playerID of [GKLocalPlayer localPlayer]
@property (nonatomic, copy) NSString *displayName; // localPlayer.playerID of [GKLocalPlayer localPlayer]
@property (nonatomic, strong) NSURL *publicKeyUrl; // publicKeyUrl of verification
@property (nonatomic, strong) NSData *signature; // signature of verification
@property (nonatomic, strong) NSData *salt; // salt of verification
@property (nonatomic, assign) uint64_t timestamp; // timestamp of verification

@property (nonatomic, strong) NSData *photoData; //user photo data (optional)

@end



/**
Facebook Login result information from FBSDKLoginManagerLoginResult
*/

@interface TTGCFacebookLoginParaModel : NSObject

@property (nonatomic, copy) NSString *accessToken; // result.token.tokenString of FacebookLoginResult
@property (nonatomic, copy) NSDate *accessExpire; // result.token.expirationDate of FacebookLoginResult

@end


/**
Twitter Login result information from TWTRSession
*/

@interface TTGCTwitterLoginParaModel : NSObject

@property (nonatomic, copy) NSString *authToken; // The authorization token.
@property (nonatomic, copy) NSString *authTokenSecret; // The authorization token secret.
@property (nonatomic, copy) NSString *userName; // The username associated with the access token.
@property (nonatomic, copy) NSString *userID; // The user ID associated with the access token.

@end



/**
appleIDCredential information from Apple protocol ASAuthorizationControllerDelegate
*/

@interface TTGCAppleIDLoginParaModel : NSObject

@property (nonatomic, copy) NSString *user; // user of appleIDCredential
@property (nonatomic, copy) NSString *familyName; // fullName.familyName of appleIDCredential (optional)
@property (nonatomic, copy) NSString *givenName; // fullName.givenName of appleIDCredential (optional)
@property (nonatomic, strong) NSData *identityToken; // identityToken of appleIDCredential

@end

NS_ASSUME_NONNULL_END
