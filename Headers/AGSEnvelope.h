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

@class AGSGeometry;
@class AGSPoint;

/** @file AGSEnvelope.h */ //Required for Globals API doc

/** @brief An envelope object.
 
 Instances of this class represent an envelope. An envelope is defined by a pair 
 of X-Y coordinates representing the lower-left and upper-right corners of a 
 rectangular bounding-box. 
 
 <code>AGSEnvelope</code> represents an immutable envelope, it cannot be altered 
 after being created. Use @c AGSMutableEnvelope for a mutable envelope. You can 
 get a mutable version from an <code>AGSEnvelope</code> by passing the 
 <code>mutableCopy</code> message to an instance of <code>AGSEnvelope</code>.

 @define{AGSEnvelope.h, ArcGIS}
 @agssince{1.0, 10.2}
 @see AGSMutableEnvelope for a mutable version.
 */
@interface AGSEnvelope : AGSGeometry 

/** X-coordinate of lower-left corner.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, readonly) double xmin;

/** Y-coordinate of lower-left corner.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, readonly) double ymin;

/** X-coordinate of upper-right corner.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, readonly) double xmax;

/** Y-cooridnate of upper-right corner.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, readonly) double ymax;

/** Center point of envelope.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSPoint *center;

/** Width of the envelope.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double width;

/** Height of the envelope.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) double height;

/** Initialize a new envelope object.
 @param xmin The bottom-left x-coordinate in map units.
 @param ymin The bottom-left y-coordinate in map units.
 @param xmax The top-right x-coordinate in map units.
 @param ymax The top-right y-coordinate in map units.
 @param spatialReference The spatial reference of envelope.
 @return A new envelope object.
 @agssince{1.0, 10.2}
 */
- (id)initWithXmin:(double)xmin ymin:(double)ymin xmax:(double)xmax ymax:(double)ymax spatialReference:(AGSSpatialReference *)spatialReference;

/** Initialize an autoreleased envelope object.
 @param xmin The bottom-left x-coordinate in map units.
 @param ymin The bottom-left y-coordinate in map units.
 @param xmax The top-right x-coordinate in map units.
 @param ymax The top-right y-coordinate in map units.
 @param spatialReference The spatial reference of envelope.
 @return A new, autoreleased, envelope object.
 @agssince{1.0, 10.2}
 @see initWithXmin:ymin:xmax:ymax:spatialReference:
 */
+ (id)envelopeWithXmin:(double)xmin ymin:(double)ymin xmax:(double)xmax ymax:(double)ymax spatialReference:(AGSSpatialReference *)spatialReference;

/** Returns <code>true</code> if argument @p point is contained within or 
 intersects the envelope. The point and the envelope must have the same spatial 
 reference.
 @param point The point to test containment.
 @return <code>true</code> if @p point is contained within envelope.
 @agssince{1.0, 10.2}
 */
- (BOOL)containsPoint:(AGSPoint *)point;

/** Returns <code>true</code> if envelope fully contains the argument @p env. 
 Both envelopes must have the same spatial reference.
 @param env The envelope to test containment.
 @return <code>true</code> if envelope is contained.
 @agssince{1.0, 10.2}
 */
- (BOOL)containsEnvelope:(AGSEnvelope *)env;

/** Simple string representation of envelope.
 @return Simple representation.
 @agssince{1.0, 10.2}
 */
- (NSString *)simpleRepresentation;

/** Returns <code>true</code> if argument @p envelope intersects this envelope. 
 Both envelopes must have the same spatial reference.
 @param envelope The envelope to test intersection relation.
 @return <code>true</code> if envelopes intersects.
 @agssince{1.0, 10.2}
 */
- (BOOL)intersectsWithEnvelope:(AGSEnvelope *)envelope;

/** Returns the intersection between this envelope and the argument @p envelope. 
 Both envelopes must have the same spatial reference.
 @param envelope The envelope to test intersection relation.
 @return Intersecting envelope else <code>nil</code>.
 @agssince{1.0, 10.2}
 */
- (AGSEnvelope *)intersectionWithEnvelope:(AGSEnvelope *)envelope;

/** Returns <code>true</code> if envelope <code>width</code> and 
 <code>height</code> are 0.
 @agssince{1.0, 10.2}
 */
- (BOOL)isEmpty;

/** Returns whether another envelope is equal to this envelope.
 @param other The other envelope.
 @return Whether the other envelope is equal to this envelope.
 @agssince{1.8, 10.2}
 */
-(BOOL)isEqualToEnvelope:(AGSEnvelope*)other;

@end


#pragma mark -

/** @brief A mutable envelope object.
 
 A mutable version of @c AGSEnvelope.
 @define{AGSEnvelope.h, ArcGIS}
 @agssince{1.0, 10.2}
 */
@interface AGSMutableEnvelope : AGSEnvelope

/** Update envelope with argument lower-left and upper-right coordinates.
 @param xmin The lower-left x-coordinate in map units.
 @param ymin The lower-left y-coordinate in map units.
 @param xmax The upper-right x-coordinate in map units.
 @param ymax The upper-right y-coordinate in map units.
 @agssince{1.0, 10.2}
 */
- (void)updateWithXmin:(double)xmin ymin:(double)ymin xmax:(double)xmax ymax:(double)ymax;

/** Recenter envelope at @p point. The point and the envelope must have the same 
 spatial reference.
 @param point The new center point.
 @agssince{1.0, 10.2}
 */
- (void)centerAtPoint:(AGSPoint *)point;

/** Update envelope by unioning with @p envelope. Both envelopes must have the 
 same spatial reference.
 @param envelope The envelope to union with.
 @agssince{1.0, 10.2}
 */
- (void)unionWithEnvelope:(AGSEnvelope *)envelope;

/**
 since 2.2
 */
- (void)unionWithPoint:(AGSPoint *)point;

/** Expand envelope by scale factor. A @p factor < 1.0 to zoom in and > 1.0 to 
 zoom out.
 @param factor The factor to expand envelope by.
 @agssince{1.0, 10.2}
 */
- (void)expandByFactor:(double)factor;

/** Expand envelope by scale factor. A @p factor < 1.0 shrinks the envelope
 and > 1.0 expands it. The @p anchorPoint and the envelope must have the same 
 spatial reference.
 @param factor The factor to scale envelope by.
 @param anchorPoint A point within the envelope to expand from.
 @agssince{1.0, 10.2}
 */
- (void)expandByFactor:(double)factor withAnchorPoint: (AGSPoint *) anchorPoint;

/** Reaspect envelope to match aspect ratio of @p size.
 @param size The size to reaspect the envelope.
 @agssince{1.0, 10.2}
 */
- (void)reaspect:(CGSize)size;


/** Offset envelope in x and y direction.
 @param offsetX The offset distance in x direction.
 @param offsetY The offset distance in y direction.
 @agssince{1.0, 10.2}
 */
- (void)offsetByX:(double)offsetX y:(double)offsetY;

/**
 @agssince{1.8, 10.2}
 */
-(void)normalize;

/**
 @agssince{1.8, 10.2}
 */
-(void)normalizeToEnvelope:(AGSEnvelope*)env;

/** Geometry's spatial reference.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

@end
