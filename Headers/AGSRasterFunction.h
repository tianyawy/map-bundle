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

/** @file AGSRasterFunction.h */

/** @brief The rendering rule to be used for an image service's export image
 operation.
 
 Specifies the processing to be done to the image service.
 @define{AGSRasterFunction.h, ArcGIS}
 @agssince{1.8, 10.2}
 */
@interface AGSRasterFunction : NSObject <AGSCoding>

/** The raster function type.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, assign) AGSRasterFunctionType type;

/** The input arguments to the raster function, in the form of an NSDictionary.
 The dictionary must be based on the JSON syntax of the arguments. Refer to the
 [REST API documentation](http://resources.arcgis.com/en/help/arcgis-rest-api/index.html#//02r3000000rv000000)
 for the JSON syntax.
 @agssince{1.8, 10.2}
 */
@property (nonatomic, strong) NSMutableDictionary *arguments;
	
@end
