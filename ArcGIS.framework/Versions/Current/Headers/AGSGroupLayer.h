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

@class AGSLayer;

/** @file AGSGroupLayer.h */ //Required for Globals API doc

/** @brief A group layer object.
 
 A group layer is a collection of AGSLayers. It can appear and act as
 a single layer and has an AGSLayer's object's properties such as visibility, extent etc.
 
 If the group layer is the map's first layer, the map will be initialized by
 the first layer (0th index) of group layer.
 @define{AGSGroupLayer.h, ArcGIS}
 @agssince{10.1.1, 10.2}
 */

@interface AGSGroupLayer : AGSLayer

/** All the @c AGSLayers in the group layer. 
 @agssince{10.1.1, 10.2} 
 */
@property (nonatomic, copy, readonly) NSArray* layers;

/** Retrieve the @c layer at @p index. 
 @param index The location of the @c AGSLayer to retrieve.
 @agssince{10.1.1, 10.2} 
 */
- (AGSLayer*)layerAtIndex:(NSUInteger)index;

@end
