Pod::Spec.new do |s|
  s.name         = "map-bundle"
  s.version      = "0.0.2"
  s.summary  = 'Progress Bar Design with Percentage values.'
  s.homepage     = "https://github.com/tianyawy/map-bundle"
  s.license      = "MIT"
  s.author             = { "yan wang" => "tianya_wy@hotmailcom" }
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/tianyawy/map-bundle.git", :tag => "0.0.2" }
  s.requires_arc = true
  s.source_files = 'Headers/*.{h,m}'
  s.resource  = "Resources/*.*"
  s.xcconfig = { 'OTHER_LDFLAGS' => '-ObjC -framework ArcGIS -l c++','Header_Search_Paths'=>'${PODS_ROOT}/Pods/map-bundle' }


end
