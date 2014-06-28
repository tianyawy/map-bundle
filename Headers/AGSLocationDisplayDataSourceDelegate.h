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

@protocol AGSLocationDisplayDataSource;
@class AGSLocation;

/** @file AGSLocationDisplayDataSourceDelegate.h */ //Required for Globals API doc

/** @brief A delegate of the location datasource.
 
 A protocol that must be adopted by any class wishing to be notified when the
 map's location datasource has an update, or is started or stopped. An instance of the class must then be set as @c AGSLocationDisplayDataSource#delegate .
  
 @define{AGSLocationDisplayDataSourceDelegate.h, ArcGIS}
 @agssince{10.1.1, 10.2}
 */
@protocol AGSLocationDisplayDataSourceDelegate <NSObject>
@required

/** Tells the delegate that the datasource is reporting new location.
 @param dataSource that has a new location to report
 @param location The new location information
 @agssince{10.1.1, 10.2}
 */
-(void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource didUpdateWithLocation:(AGSLocation*)location;

/** Tell the delegate that the datasource is reporting a new heading.
 @param dataSource that has a new heading to report
 @param heading The new heading information
 @agssince{10.1.1, 10.2}
 */
-(void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource didUpdateWithHeading:(double)heading;

/** Tell the delegate that the datasource is reporting a new heading.
 @param dataSource that has a new heading to report
 @param error The error that occurred
 @agssince{10.1.1, 10.2}
 */
-(void)locationDisplayDataSource:(id<AGSLocationDisplayDataSource>)dataSource didFailWithError:(NSError*)error;

/** Tells the delegate that the datasource was stopped.
 @param dataSource that was stopped
 @agssince{10.1.1, 10.2}
 */
-(void)locationDisplayDataSourceStopped:(id<AGSLocationDisplayDataSource>)dataSource;

/** Tells the delegate that the datasource was started.
 @param dataSource that was started
 @agssince{10.1.1, 10.2}
 */
-(void)locationDisplayDataSourceStarted:(id<AGSLocationDisplayDataSource>)dataSource;
@end
