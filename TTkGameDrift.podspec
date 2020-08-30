Pod::Spec.new do |spec|

  spec.name         = "TTkGameDrift"
  spec.version      = "1.1.12"
  spec.summary      = "TTkGame SDK for games"
  
  spec.description  = <<-DESC
  TTkGame SDK for games
  Convenient game access
  DESC

  spec.homepage     = "https://github.com/AmuseGames/GameSDK-iOS"

  spec.license      = { :type => "MIT" }

  spec.author             = "AmuseGames Team"
  
  spec.platform     = :ios, "9.0"
  spec.ios.deployment_target = "9.0"
  
  spec.source       = { :git => "https://github.com/AmuseGames/GameSDK-iOS.git", :tag => "Drift-1.1.12" }

  spec.requires_arc = true
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  #是否使用静态库。如果podfile指明了use_frameworks!命令，但是pod仓库需要使用静态库则需要设置
  spec.static_framework = true
  spec.libraries = 'sqlite3'
  spec.frameworks = 'UIKit', 'StoreKit', 'GameKit', 'WebKit', 'UserNotifications', 'Photos', 'ImageIO', 'Foundation', 'CoreFoundation', 'QuartzCore', 'CoreGraphics', 'AVFoundation', 'CoreTelephony', 'Security', 'AuthenticationServices'
    
  spec.subspec 'Core' do |cr|
      cr.vendored_framework = 'SDK/TTkGameDrift/Core/TTkGameSDK.framework'
      cr.resources = 'SDK/TTkGameDrift/Core/TTkGame.bundle','SDK/TTkGameDrift/Core/TTGCProgressHUD.bundle'
  end
  
  spec.subspec 'Facebook' do |fb|
      fb.source_files = 'SDK/TTkGameDrift/SocialLibraries/Facebook'
      fb.vendored_library = 'SDK/TTkGameDrift/SocialLibraries/Facebook/libTTGCSocialFacebook.a'
      fb.dependency 'FBSDKCoreKit', '~> 6.5.1'
      fb.dependency 'FBSDKLoginKit', '~> 6.5.1'
      fb.dependency 'FBSDKShareKit', '~> 6.5.1'
      fb.dependency 'TTkGameDrift/Core'
  end
  
  spec.subspec 'Twitter' do |tt|
      tt.source_files = 'SDK/TTkGameDrift/SocialLibraries/TTGCSocialTwitter'
      tt.vendored_library = 'SDK/TTkGameDrift/SocialLibraries/TTGCSocialTwitter/libTTGCSocialTwitter.a'
      tt.dependency 'TwitterKit5'
      tt.dependency 'TTkGameDrift/Core'
  end
  
  spec.subspec 'Analytics' do |analy|
      analy.source_files = 'SDK/TTkGameDrift/SocialLibraries/TTGCAnalytics'
      analy.vendored_library = 'SDK/TTkGameDrift/SocialLibraries/TTGCAnalytics/libTTGCAnalytics.a'
      analy.dependency 'Firebase/Analytics'
      analy.dependency 'Firebase/DynamicLinks'
      analy.dependency 'TTkGameDrift/Core'
  end
  
  spec.subspec 'AppsFlyer' do |af|
      af.source_files = 'SDK/TTkGameDrift/SocialLibraries/TTGCAppsFlyer'
      af.vendored_library = 'SDK/TTkGameDrift/SocialLibraries/TTGCAppsFlyer/libTTGCAppsFlyer.a'
      af.dependency 'AppsFlyerFramework'
      af.dependency 'TTkGameDrift/Core'
  end
  
  spec.subspec 'Tapjoy' do |tg|
      tg.source_files = 'SDK/TTkGameDrift/SocialLibraries/TTGCTapjoy'
      tg.vendored_library = 'SDK/TTkGameDrift/SocialLibraries/TTGCTapjoy/libTTGCTapjoy.a'
      tg.dependency 'TapjoySDK'
      tg.dependency 'TTkGameDrift/Core'
  end

end
