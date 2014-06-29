/*
 COPYRIGHT 2013 ESRI
 
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


#import <Foundation/Foundation.h>

@class AGSMapContentsLayerInfo;
@class AGSMapView;
@class AGSWebMap;

AGS_EXTERN NSString *const AGSMapContentsDidChangeNotification;

/** @brief
 
 A class that is used to generate a tree that represents the layers in a map.
 
 @agssince{10.2, 10.2}
 */

@interface AGSMapContentsTree : NSObject

/**
 The root of the layer tree.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSMapContentsLayerInfo* root;

/**
 The mapView with which the MapContentsTree was initialized
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly)AGSMapView* mapView;

/**
 The webMap with which the MapContentsTree was initialized
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSWebMap* webMap;

/**
 Layers that will be excluded from the layer tree.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, copy)NSSet* excludeList;

/**
 The manage layer visibility setting with which the MapContentsTree was initialized.
 When set to YES the map content tree will show the visibility and set the visibility 
 of layers; when NO the map contents tree only shows the visibility of layer.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, readonly) BOOL manageLayerVisibility;

/**
 Initializer.  Use this when you are adding layers to a map without using
 a Web Map.  With this initializer the Map Contents Tree will listen for
 notifications that layers have been added or deleted and update accordingly.
 Parameters:
 mapView: The map that the layer tree will represent
 @agssince{10.2, 10.2}
 */
- (id)initWithMapView:(AGSMapView*)mapView;

/**
 Initializer.  Use this when you are adding layers to a map without using
 a Web Map.  With this initializer the Map Contents Tree will listen for
 notifications that layers have been added or deleted and update accordingly.
 Parameters:
 mapView: The map that the layer tree will represent
 manageLayerVisibility: When YES, AGSMapContentsLayerInfo objects will set the
 visibility of layers and sub-layers to be consistent that object's visible property
 @agssince{10.2, 10.2}
 */
- (id)initWithMapView:(AGSMapView*)mapView manageLayerVisibility:(BOOL)manageLayerVisibility;

/**
 Initializer.  Use this initializer when you have a Web Map that will be 
 opened into the Map View.  With this initializer the Map Contents Tree will
 use layer names from the Web Map and lay out the Tree to match the constuction
 of the Web Map
 Parameters:
 webMap: The web map that the layer tree will represent
 @agssince{10.2, 10.2}
 */
- (id)initWithWebMap:(AGSWebMap*)webMap mapView:(AGSMapView*)mapView;

/**
 Initializer.  Use this initializer when you have a Web Map that will be
 opened into the Map View.  With this initializer the Map Contents Tree will
 use layer names from the Web Map and lay out the Tree to match the constuction
 of the Web Map
 Parameters:
 webMap: The web map that the layer tree will represent
 manageLayerVisibility: When YES, AGSMapContentsLayerInfo objects will set the
 visibility of layers and sub-layers to be consistent that object's visible property
 @agssince{10.2, 10.2}
 */
- (id)initWithWebMap:(AGSWebMap*)webMap mapView:(AGSMapView*)mapView manageLayerVisibility:(BOOL)manageLayerVisibility;

@end

