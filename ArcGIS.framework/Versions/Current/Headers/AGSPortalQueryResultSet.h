/*
 COPYRIGHT 2011 ESRI
 
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

@class AGSPortalQueryParams;

/** @file AGSPortalQueryResultSet.h */ //Required for Globals API doc

/** @brief Results of a query on a portal 
 
 Instances of this class respresent results of a query peformed on the portal. 
 
 @see AGSPortalQueryParams
 @agssince{2.2, 10.2}
 */
@interface AGSPortalQueryResultSet : NSObject

/** The query params that was used to make the search. 
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSPortalQueryParams *queryParams;

/** The query params for the next set of results based on the next start index. This is automatically 
 generated if there are any more results left to be retrieved. <code>nil</code> if there are no more 
 results for the next page. 
 @agssince{2.2, 10.2}
 */
@property (nonatomic, strong, readonly) AGSPortalQueryParams *nextQueryParams;

/** The total number of results irrespective of the paging. 
 @agssince{2.2, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger totalResults;

/** The present results of the query. It could be and array of @c AGSPortalGroup or @c AGSPortalItem depending on the query that was performed
 @agssince{2.2, 10.2}
 */
@property (nonatomic, copy, readonly) NSArray *results;
@end
