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



/** @file AGSWebMapQuery.h */ //Required for Globals API doc

/** @brief A predefined query stored in a web map
 
 Instances of this class represent predefined queries stored in a web map. The query contains information that can be combined with user input to execute queries using the @c AGSQueryTask. 
 @agssince{2.2, 10.2}
 */
@interface AGSWebMapQuery : NSObject <AGSCoding>

/** The name of this query in the webmap.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSString *name;

/**
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSString *displayField;

/** The URL of the layer to query. The URL points to a REST resource that represents a layer in a Map, Image, or Feature service. This URL can be used to instantiate an @c AGSQueryTask
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readwrite) NSURL *URL;

/** The general structure of an SQL where clause to perform the query. The clause contains numbered placeholders such as {0} {1} which need to be replaced with predicates that are constructed from items in the @c #parameters list.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSString *whereClause;

/** An array of @c AGSWebMapQueryParameter objects representing the predicates to be used in the @c #whereClause.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSArray *parameters;

/**
 An array of strings representing the fields that must be returned in the results.
 This array can be used with @c AGSQuery#outFields.
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readwrite) NSArray *visibleFields;

@end
