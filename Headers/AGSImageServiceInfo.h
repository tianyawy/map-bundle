/*
 COPYRIGHT 2010 ESRI
 
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

@protocol AGSCoding;

@class AGSEnvelope;
@class AGSTimeInfo;

/** @file AGSImageServiceInfo.h */ //Required for Globals API doc

/** @brief Information about an ArcGIS Server image service.
 
 Instances of this class represent information about an ArcGIS Server image service.
 
 @define{AGSImageServiceInfo.h, ArcGIS}
 @agssince{1.0, 10.2}
 */
@interface AGSImageServiceInfo : NSObject <AGSCoding>

/** The image service description.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The name of raster image or data.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The extent of the image service.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSEnvelope *extent;

/** The pixel size along X-axis.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double pixelSizeX;

/** The pixel size along Y-axis.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double pixelSizeY;

/** The number of bands in the image service.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger bandCount;

/** The type of data at each pixel.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *pixelType;

/** The minimum pixel size.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double minPixelSize;

/** The maximum pixel size.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double maxPixelSize;

/** Copyright text of the image service.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *copyrightText;

/** The data type of the image service.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *serviceDataType;

/** Minumum value in each image band.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *minValues;

/** Maximum value in each image band.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *maxValues;

/** Mean value in each image band.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *meanValues;

/** Standard deviation value in each image band.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *stdvValues;

/** The version of ArcGIS Server the image service is published to, e.g. 9.3, 
 9.3.1, 10.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, readonly) float version;

/** Temporal information for the layer, such as time extent. If this property is
 null or not specified, then the layer does not support time-related operations.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, strong, readonly) AGSTimeInfo *timeInfo;

/** The name of the object ID field.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *objectIdField;

/** The fields of the image service as specified in the Service Directory.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *fields;



@end







