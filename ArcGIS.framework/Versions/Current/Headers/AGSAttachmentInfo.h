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

/** @file AGSAttachmentInfo.h */ //Required for Globals API doc

/** @brief Information about an attachment.
 
 Information about an attachment associated with a feature.

 @define{AGSAttachmentInfo.h, ArcGIS}
 @agssince{1.0, 10.2}
 @see AGSFeatureLayerEditingDelegate
 */
@interface AGSAttachmentInfo : NSObject <AGSCoding>

/** The unique id of the attachment in the database.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger attachmentId;

/** The MIME type of the attachment.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/** The size of the attachment in bytes.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** The name of the attachment.
 @agssince{1.0, 10.2}
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Compares one attachment info to another.
 @agssince{1.8, 10.2}
 */
-(BOOL)isEqualToAttachmentInfo:(AGSAttachmentInfo*)other;

@end
