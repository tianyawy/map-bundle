/*
 COPYRIGHT 2009 ESRI
 
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

/** @file AGSCoding.h */ //Required for Globals API doc

/** @brief A protocol to convert objects to and from JSON.

 This protocol must be adopted by all classes which wish to allow decoding/encoding 
 from/to JSON.
 @define{AGSCoding.h, ArcGIS}
 @agssince{1.0, 10.2}
 */

@protocol AGSCoding <NSObject>

@optional

/** Initialize and return object from JSON representation.
 @param json The JSON representation of the object to be created.
 @return Object decoded from JSON representation.
 @agssince{1.0, 10.2}
 */
- (id)initWithJSON:(NSDictionary *)json;

/** Decode object from JSON representation.
 @param json The JSON representation of the object to be decoded.
 @agssince{1.0, 10.2}
 */
- (void)decodeWithJSON:(NSDictionary *)json;

/** Encode and return JSON representation for object.
 @return JSON representation of object.
 @agssince{1.0, 10.2}
 */
- (NSDictionary *)encodeToJSON;

@end
