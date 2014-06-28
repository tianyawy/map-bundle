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

/** @file AGSTileKey.h */ //Required for Globals API doc

/** @brief A tile key
 
 Instances of this class represent a "key" that uniquely identifies a tile in a tiling scheme.
 
 @agssince{10.1.1, 10.2}
 */

@interface AGSTileKey : NSObject <NSCopying>

/** The column of tiling scheme.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) NSInteger column;

/** The row of tiling scheme
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) NSInteger row;

/** The level of tiling scheme
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, assign) NSInteger level;

/** Return an initialized @c AGSTileKey object
 @param c column
 @param r row
 @param l level
 @agssince{10.1.1, 10.2}
 */
-(id)initWithColumn:(NSInteger)c row:(NSInteger)r level:(NSInteger)l;

/** Return an autoreleased and initialized @c AGSTileKey object
 @param c column
 @param r row
 @param l level
 @agssince{10.1.1, 10.2}
 */
+(AGSTileKey*)tileKeyWithColumn:(NSInteger)c row:(NSInteger)r level:(NSInteger)l;

/** Indicates whether the given tile key is equal to the current object
 @param key Tile key to compare to
 @agssince{10.1.1, 10.2}
 */
-(BOOL)isEqualToTileKey:(AGSTileKey*)key;
@end
