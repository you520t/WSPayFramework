Pod::Spec.new do |s|
  s.name = "WSPay"
  s.version = "0.1.0"
  s.summary = "WSPay."
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"you520t"=>"liaochenyu@wesai.com"}
  s.homepage = "http://gitlab.intra.wesai.com/liaochenyu/iOS_wesaiPay"
  s.description = "TODO: Add long description of the pod here."
  s.frameworks = ["UIKit", "CoreTelephony", "SystemConfiguration", "CoreGraphics"]
  s.xcconfig = {"OTHER_LDFLAGS"=>"-lObjC"}
  s.source = { :path => '.' }

  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'ios/WSPay.framework'
  s.ios.resource=['ios/Resource/**/*.{xcassets,wav,mp3,xib,txt}']
end