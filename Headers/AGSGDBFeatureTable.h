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

@class AGSSpatialReference;
@class AGSGDBGeodatabase;
@class AGSQuery;
@class AGSRelationshipQuery;
@class AGSGDBQueryResultCursor;
@class AGSEditFieldsInfo;
@class AGSGDBFeature;
@class AGSFeatureTable;
@class AGSCredential;
@class AGSFeatureType;
@class AGSFeatureTemplate;
@protocol AGSFeature;
@protocol AGSGDBFeatureSourceInfo;

/** @file AGSGDBFeatureTable.h */ //Required for Globals API doc

/** @brief A dataset in a local geodatabase
 
 Instances of this class represent datasets in a local geodatabase. The dataset may contain
 geographic features, or non-geographic records (@c #isTableOnly).
 
 You can potentially create, delete, and update the data depending upon whether the originating datasource allows those operations, who owns the data, and what ownership-based access control policies are in place. Refer to the @c  #canCreate, @c #canUpdate, @c #canDelete, @c #canUpdateFeature:, @c #canDeleteFeature:, @c #canUpdateGeometry for information on what's permitted.
 
 If the data supports attachments (@c #hasAttachments), you can also view and potentially edit the attachments.
 
 You can also query the data based on SQL expressions and/or spatial relationships.
 
 @see @c AGSFeatureTableLayer to visualize features from this dataset on a map.
 @see @c AGSGDBSyncTask to generate a geodatabase from an ArcGIS Feature service
 @define{AGSGDBFeatureTable.h, ArcGIS}
 @agssince{10.2, 10.2}
 */
@interface AGSGDBFeatureTable : AGSFeatureTable <AGSGDBFeatureSourceInfo> 

/** The local geodatabase this dataset belongs to
 @since 10.2
 */
@property (nonatomic, weak, readonly) AGSGDBGeodatabase *geodatabase;

#pragma mark feature source info properties

/** The credential to be used to access the secured feature source.
 @since 10.2
 */
@property (nonatomic, copy, readonly) AGSCredential *credential;

/** The geometry type of features contained in source.
 All features will have the same geometry type.
 Possible types include
 @li @c AGSGeometryTypePoint
 @li @c AGSGeometryTypePolyline
 @li @c AGSGeometryTypePolygon
 
 @c AGSGeometryTypeMultipoint and @c AGSGeometryTypeEnvelope types are not supported.
 @since 10.2
 */
@property (nonatomic, readonly) AGSGeometryType geometryType;

/** The primary display field of features. This field will contain information about the feature that is most relevant to a user.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *displayField;

/** The fields available in the source as an
 array of @c AGSField objects. The value of each field is available as feature attributes.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *fields;

/** The name of field which contains the @em OBJECTID for each feature
 @since 10.2
 @see #objectIdForFeature: to conveniently get a feature's @em OBJECTID.
 */
@property (nonatomic, copy, readonly) NSString *objectIdField;

/** The name of the field which contains the sub-type information for each feature.
 @avail{10.0}
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *typeIdField;

/** A collection of @c AGSFeatureType objects representing feature sub-types. For example, a @em source representing roads may contain 2 feature sub-types : highways
 and streets.
 @avail{10.0}
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *types;

/** A collection of @c AGSFeatureTemplate objects representing feature templates. Usually only present if feature
 sub-types are unavialable.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *templates;

/** Metadata regarding which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEditFieldsInfo *editFieldsInfo;

/** If <code>YES</code>, features may have attachments.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL hasAttachments;

/** If @c YES, the source contains non-geographic data.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL isTableOnly;

/** Indicates whether the source allows new features to be created.
 You should check this property before allowing the ability to create a new feature in your app.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canCreate;

/** Indicates whether the source allows a feature to be updated.
 It is preferable to use #canUpdateFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to edit.
 It only provides general information about whether the source is capable of allowing feature updates at all.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdate;

/** Indicates whether the source allows features to be deleted.
 It is preferable to use #canDeleteFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to delete.
 It only provides general information about whether the layer is capable of allwoing feature deletions at all.
 @since 10.2
 @see #canDeleteFeature:
 */
@property (nonatomic, assign, readonly) BOOL canDelete;

/** Indicates whether the source allows geometries of features to be updated.
 You should check this property before allowing the ability to update a feature's geometry in your app.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

/** Indicates whether the source allows updating this particular feature. The method first checks #canUpdate to verify if the layer is capable of updating any features in general. It also checks ownership-based access control policies of the source to see if the  user specified in the #credential has persmissions to edit this specific feature.
 You should check this property before allowing the ability to update this feature in your app.
 @param feature Can be nil, in which case, this method is the same as #canUpdate
 @return A boolean value
 @since 10.2
 */
- (BOOL)canUpdateFeature:(id<AGSFeature>)feature;

/** Indicates whether the source allows this particular feature to be delete. The method first checks #canDelete to verify if the source is capable of deleting any features in general. It also checks ownership-based access control policies of the source to see if the  user specified in the #credential has persmissions to delete this specific feature.
 @param feature Can be nil, in which case, this method is the same as #canDelete
 @return A boolean value
 @since 10.2
 */
- (BOOL)canDeleteFeature:(id<AGSFeature>)feature;

#pragma mark query methods

/**
 Finds the feature with the specified objectID.
 */
-(void)queryFeatureWithObjectID:(long long)objectID completion:(void (^)(AGSGDBFeature *feature, NSError *error))completion;

/** Query the dataset for results coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning an array of results or an NSError if an error occured. The results are @c id<AGSFeature> objects or, if statistics are requested, they are @c NSDictionary objects.
@return void
 @agssince{10.2, 10.2}
 */
-(void)queryResultsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *results, NSError *error))completion;

/** Query the dataset for a cursor of results coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning cursor of results or an NSError if an error occured.
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryResultCursorWithParameters:(AGSQuery*)params completion:(void (^)(AGSGDBQueryResultCursor *cursor, NSError *error))completion;

/** Query the dataset for an array of object IDs coresponding to the query parameters
 @param query AGSQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning an array of object IDs
 and an NSError if an error occured.
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryObjectIDsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *objectIDs, NSError *error))completion;

/** Retrieves all the relationships this dataset participates in
 @return an array of AGSRelationship objects
 @agssince{10.2, 10.2}
 */
-(NSArray*)relationships;

/** Query the geodatabase for the features/records related to a list of features in this dataset.
 @param relatedQueryParams @c AGSRelationshipQuery parameters that define the query.
 @param completion The block that is called when the query is complete, returning a dictionary of reults or an NSError if an error occured. The results contain @c AGSGDBQueryResultCursor objects with associated object ID
 @return void
 @agssince{10.2, 10.2}
 */
-(void)queryRelatedFeaturesWithParameters:(AGSRelationshipQuery*)relatedQueryParams completion:(void (^)(NSDictionary *results, NSError *error))completion;

#pragma mark other

/** Saves the specified feature to the table. 
 If the feature is not yet in the table, this method will add it. If the feature is already in the table then
 this method will update it.
 @param feature to save.
 @param error result of the operation
 @since 10.2.2
 @see @c #canCreate and @c #canUpdate to check if the table allows features to be added or updated in general
 @see @c #canUpdateFeature: to check if a particular feature can be updated based on the table's ownership-based access control policies
 */
-(BOOL)saveFeature:(AGSGDBFeature*)feature error:(NSError**)error;

/**
 Saves the specified features to the table.
 If the feature is not yet in the table, this method will add it. If the feature is already in the table then
 this method will update it.
 If one of the features fails, all will be rolled back. The error will contain the objectID of the feature that failed.
 @param features to save.
 @param error result of the operation
 @since 10.2.3
 @see @c #canCreate and @c #canUpdate to check if the table allows features to be added or updated in general
 @see @c #canUpdateFeature: to check if a particular feature can be updated based on the table's ownership-based access control policies
 */
-(BOOL)saveFeatures:(NSArray*)features error:(NSError**)error;

/** Deletes the specified feature in the dataset.
 @param feature to delete.
 @param error result of the operation
 @return result of the operation
 @since 10.2
 @see @c #canDelete to check if the table allows features to be deleted in general
 @see @c #canDeleteFeature: to check if a particular feature can be deleted based on the table's ownership-based access control policies
 */
-(BOOL)deleteFeature:(AGSGDBFeature*)feature error:(NSError**)error;

/** Deletes the specified features in the dataset.
 If one of the features fails, all will be rolled back. The error will contain the objectID of the feature that failed.
 @param features to delete.
 @param error result of the operation
 @return result of the operation
 @since 10.2.3
 @see @c #canDelete to check if the table allows features to be deleted in general
 @see @c #canDeleteFeature: to check if a particular feature can be deleted based on the table's ownership-based access control policies
 */
-(BOOL)deleteFeatures:(NSArray*)features error:(NSError**)error;

/** Indicates whether any edits (adds/updates/deletes) have been
 made to the dataset since the specified date.
 @param date
 @return @c YES or @c NO
 */
-(BOOL)hasLocalEditsSince:(NSDate*)date;

/**
 Set of @c id<AGSFeature> objects that have been added to the dataset.
 @since 10.2
 */
-(NSSet*)addedFeatures;

/**
 Set of @c id<AGSFeature> objects that have been updated.
 @since 10.2
 */
-(NSSet*)updatedFeatures;

/**
 Set of @c id<AGSFeature> objects that have been deleted from the dataset.
 @since 10.2
 */
-(NSSet*)deletedFeatures;

/**
 Returns the number of @c id<AGSFeature> objects that have been added to the dataset.
 @return The number of features added.
 @since 10.2.2
 */
-(NSUInteger)addedFeaturesCount;

/**
 Returns the number of @c id<AGSFeature> objects that have been updated in the dataset.
 @return The number of features updated.
 @since 10.2.2
 */
-(NSUInteger)updatedFeaturesCount;

/**
 Returns the number of @c id<AGSFeature> objects that have been deleted from the dataset.
 @return The number of features deleted.
 @since 10.2.2
 */
-(NSUInteger)deletedFeaturesCount;

/** Creates a new autoreleased feature based on the specified feature sub-type and feature
 template. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @return The new feature.
 @since 10.2
 @see @c #saveFeature:error: for
 adding the feature to the dataset.
 */
-(AGSGDBFeature*)featureWithTemplate:(AGSFeatureTemplate*)featureTemplate;

/** Creates a new autoreleased feature based on the specified feature sub-type. Note, the new
 feature is only available in memory at this point, it is not commited to
 the dataset. This method uses the first template in the feature type.
 @param featureType The type of feature to create.
 @return The new feature.
 @since 10.2
 @see @c #saveFeature:error: for
 adding the feature to the dataset.
 */
-(AGSGDBFeature*)featureWithType:(AGSFeatureType*)featureType;

@end
