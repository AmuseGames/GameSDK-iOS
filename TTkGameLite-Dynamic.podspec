Pod::Spec.new do |spec|

  spec.name         = "TTkGameLite-Dynamic"
  spec.version      = "1.0.6"
  spec.summary      = "TTkGame SDK for games"
  
  spec.description  = <<-DESC
  TTkGame SDK for games
  Convenient game access
  DESC

  spec.homepage     = "https://github.com/AmuseGames/GameSDK-iOS"
  spec.license      = { :type => "MIT" }
  spec.author       = "AmuseGames Team"
  
  spec.platform     = :ios, "9.0"
  spec.ios.deployment_target = "9.0"
  
  spec.source       = { :git => "https://github.com/AmuseGames/GameSDK-iOS.git", :tag => "TTkGameLite-Dynamic-1.0.6" }

  spec.requires_arc = true
  spec.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  spec.libraries = 'sqlite3'
  spec.frameworks = 'UIKit', 'StoreKit', 'GameKit', 'WebKit', 'UserNotifications', 'Photos', 'ImageIO', 'Foundation', 'CoreFoundation', 'QuartzCore', 'CoreGraphics', 'AVFoundation', 'CoreTelephony', 'Security', 'AuthenticationServices'
    
  spec.subspec 'Core' do |cr|
      cr.vendored_framework = 'SDK/TTkGameLite-Dynamic/Core/TTkGameSDK.framework'
      cr.resource = 'SDK/TTkGameLite-Dynamic/Core/TTkGame.bundle'
  end
  
  spec.subspec 'Analytics' do |analy|
      analy.source_files = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCAnalytics'
      analy.vendored_library = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCAnalytics/libTTGCAnalytics.a'
      analy.dependency 'TTkGameLite-Dynamic/Core'
      analy.dependency 'Firebase/Analytics'
      analy.dependency 'Firebase/DynamicLinks'
  end
  
  spec.subspec 'AppsFlyer' do |af|
      af.source_files = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCAppsFlyer'
      af.vendored_library = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCAppsFlyer/libTTGCAppsFlyer.a'
      af.dependency 'AppsFlyerFramework', '~> 5.4.0'
      af.dependency 'TTkGameLite-Dynamic/Core'
  end
  
  spec.subspec 'Tapjoy' do |tg|
      tg.source_files = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCTapjoy'
      tg.vendored_library = 'SDK/TTkGameLite-Dynamic/SocialLibraries/TTGCTapjoy/libTTGCTapjoy.a'
      tg.dependency 'TapjoySDK'
      tg.dependency 'TTkGameLite-Dynamic/Core'
  end

end
