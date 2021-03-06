/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

@class AGSGraphic;

/** @file AGSFeatureTemplate.h */ //Required for Globals API doc

/** @brief Represents all of the information needed to create a feature.
 
 Instances of this class represent a feature template. A feature template
 defines all the information required to create a feature: the layer where a
 feature will be stored and the attributes a feature is created with.
 
 @agssince{1.0, 10.2}
 */
@interface AGSFeatureTemplate : NSObject <AGSCoding>

/** Name of the template.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Description of the template.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *featureDescription;

/** A prototypical feature associated with the template which can be used to 
 easily create new features. The prototype specifies default values for the 
 feature's attributes, however, it does not contain a geometry.
 @deprecated Deprecated at 10.2 Use @c AGSFeatureTemplate#prototypeAttributes instead.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSGraphic *prototype __attribute__((deprecated));

/** The attributes of a prototypical feature associated with the template. The template specifies
 default values for many of the attributes and can be used to
 easily create new features.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSDictionary *prototypeAttributes;

@end