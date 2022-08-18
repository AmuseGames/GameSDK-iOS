Pod::Spec.new do |spec|

  spec.name         = "AmuseGameSDK"
  spec.version      = "2.2.6"
  spec.summary      = "AmuseGame SDK for games"
  
  spec.description  = <<-DESC
  AmuseGame SDK for games
  Convenient game access
  DESC

  spec.homepage     = "https://github.com/AmuseGames/GameSDK-iOS"

  spec.license      = { :type => "MIT" }

  spec.author             = "AmuseGames Team"
  
  spec.platform     = :ios, "11.0"
  spec.ios.deployment_target = "11.0"
  
  spec.source       = { :git => "https://github.com/AmuseGames/GameSDK-iOS.git", :tag => "2.2.6" }

  spec.requires_arc = true
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  #是否使用静态库。如果podfile指明了use_frameworks!命令，但是pod仓库需要使用静态库则需要设置
  spec.static_framework = true
  spec.libraries = 'sqlite3'
  spec.frameworks = 'UIKit', 'StoreKit', 'GameKit', 'WebKit', 'UserNotifications', 'Photos', 'ImageIO', 'Foundation', 'CoreFoundation', 'QuartzCore', 'CoreGraphics', 'AVFoundation', 'CoreTelephony', 'Security', 'AuthenticationServices'
    
  spec.subspec 'Core' do |cr|
      cr.vendored_framework = 'SDK/AmuseGameSDK/Core/AmuseGameSDK.framework'
      cr.resources = 'SDK/AmuseGameSDK/Core/G_ICON_B.bundle','SDK/AmuseGameSDK/Core/G_ICON_ProgressHUD.bundle','SDK/AmuseGameSDK/Core/DACON.bundle'
  end

  spec.subspec 'CustomUI' do |cu|
      cu.dependency 'IQKeyboardManager'
      cu.dependency 'AmuseGameSDK/Core'
  end
  
  spec.subspec 'Facebook' do |fb|
      fb.source_files = 'SDK/AmuseGameSDK/SocialLibraries/Facebook'
      fb.vendored_library = 'SDK/AmuseGameSDK/SocialLibraries/Facebook/libTTGCSocialFacebook.a'
      fb.dependency 'FBSDKCoreKit'
      fb.dependency 'FBSDKLoginKit'
      fb.dependency 'FBSDKShareKit'
      fb.dependency 'AmuseGameSDK/Core'
  end
  
  spec.subspec 'Twitter' do |tt|
      tt.source_files = 'SDK/AmuseGameSDK/SocialLibraries/TTGCSocialTwitter'
      tt.vendored_library = 'SDK/AmuseGameSDK/SocialLibraries/TTGCSocialTwitter/libTTGCSocialTwitter.a'
      tt.dependency 'TwitterKit5', '~> 5.2.0'
      tt.dependency 'AmuseGameSDK/Core'
  end
  
  spec.subspec 'Analytics' do |analy|
      analy.source_files = 'SDK/AmuseGameSDK/SocialLibraries/TTGCAnalytics'
      analy.vendored_library = 'SDK/AmuseGameSDK/SocialLibraries/TTGCAnalytics/libTTGCAnalytics.a'
      analy.dependency 'Firebase/Analytics'
      analy.dependency 'Firebase/DynamicLinks'
      analy.dependency 'Firebase/Auth'
      analy.dependency 'GoogleSignIn'
      analy.dependency 'AmuseGameSDK/Core'
  end
  
  spec.subspec 'AppsFlyer' do |af|
      af.source_files = 'SDK/AmuseGameSDK/SocialLibraries/TTGCAppsFlyer'
      af.vendored_library = 'SDK/AmuseGameSDK/SocialLibraries/TTGCAppsFlyer/libTTGCAppsFlyer.a'
      af.dependency 'AppsFlyerFramework'
      af.dependency 'AmuseGameSDK/Core'
  end
  
  spec.subspec 'Tapjoy' do |tg|
      tg.source_files = 'SDK/AmuseGameSDK/SocialLibraries/TTGCTapjoy'
      tg.vendored_library = 'SDK/AmuseGameSDK/SocialLibraries/TTGCTapjoy/libTTGCTapjoy.a'
      tg.dependency 'TapjoySDK'
      tg.dependency 'AmuseGameSDK/Core'
  end

end
