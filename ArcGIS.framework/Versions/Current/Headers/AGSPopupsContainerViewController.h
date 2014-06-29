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

//#import <UIKit/UIKit.h>

@protocol AGSPopupsContainer;
@protocol AGSPopupsContainerDelegate;

@class AGSPopupViewController;
@class AGSGeometry;
@class AGSPopup;
@class AGSAttachmentCollectorViewController;
@class AGSWebMap;
@class AGSPopupInfo;
@class AGSGraphic;
@class AGSViewController;

/** @file AGSPopupsContainerViewController.h */ //Required for Globals API doc

/**@brief A view controller for displaying popups
 
 Instances of this class represent a view controller that provides the basic user interface
 (UI) and behavior for displaying and editing information about graphics in a popup. It is a container 
 and manages a number of view controllers behind the scenes, each of which is designed for a specific purpose, 
 such as editing an attribute, displaying media, managing attachments, etc.
 It manages transitions between these view controllers and displays the relevant one
 depending upon what the user intends to do.
 @see @concept{working-with-web-map-popups.htm, Working With Web Map Popups}
 @see @sample{2ddb261648074b9aabb22240b6975918, Feature Layer Editing}
 @agssince{2.0, 10.2}
 */
#if TARGET_OS_IPHONE

@interface AGSPopupsContainerViewController : AGSViewController <UIScrollViewDelegate, AGSPopupsContainer, UIActionSheetDelegate>

/** The UIView that will act as a container for any UIActionSheet.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, weak) UIView *actionSheetContainerView;

/** You can replace the button that appears on the left side of the Navigation Bar
 with a custom button through this property.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *doneButton;

/** You can replace the button that appears on the right side of the Navigation Bar
 with a custom button through this property.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *actionButton;

/** The default action button that is shown.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultActionButton;

/** The default done button that is shown.
 @agssince{2.1, 10.2}
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultDoneButton;

/** The style that is used for editing.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, assign) AGSPopupsContainerEditingStyle editingStyle;

/** The UIViewController that should be used for presenting modal view controllers
 from within this AGSPopupsContainer. This is useful when using this view controller
 as a standalone object (for example, in a custom callout or a custom view)  and when it's not part of a view controller hierarchy.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, strong) UIViewController *modalPresenter;

/** The style that is used for paging when multiple popups are being displayed.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, assign) AGSPopupsContainerPagingStyle pagingStyle;

/** The style for the AGSPopupsContainer.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, assign) AGSPopupsContainerStyle style;

/** The color that is used for the toolbars and navigation bars in the popup views when @c #style
 is set to @c AGSPopupsContainerStyleCustomColor.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, strong) AGSColor *styleColor;

/** Sets the tint color of items in toolbars and navigation bars that appear in the popup.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 This property only works on iOS 7 and above.
  @agssince{10.2, 10.2}
 */
@property (nonatomic, strong) AGSColor *barItemTintColor;

/** Sets whether toolbars and navigation bars that appear in the popup are translucent.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, assign) BOOL barTranslucent;

/** Sets the tint color of titles in toolbars and navigation bars that appear in the popup.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 @agssince{10.2, 10.2}
 */
@property (nonatomic, strong) AGSColor *barTitleTintColor;

/** Font used for heading text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSFont *headlineFont;
    
/** Color used for heading text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *headlineColor;

/** Font used for attribute title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSFont *attributeTitleFont;

/** Font used for attribute detail text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSFont *attributeDetailFont;

/** Font used for small attachment title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSFont *attachmentTitleFont;

/** Color of text used for attribute title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *attributeTitleColor;

/** Color of text used for attribute detail text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *attributeDetailColor;

/** Initializes an AGSPopupsContainerViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @param usingNavigationControllerStack A boolean indicating whether the
 navigation controller in the application should be updated when displaying popups
 @agssince{2.0, 10.2}
 */
-(id)initWithPopups:(NSArray *)popups usingNavigationControllerStack:(BOOL)usingNavigationControllerStack;

/** Initializes an AGSPopupsContainerViewController with an AGSPopupInfo and an AGSGraphic.
 The feature must belong to the graphics collection of an AGSFeatureLayer.
 @param popupInfo representing the popup definition
 @param graphic for which to display the popup
 @param usingNavigationControllerStack A boolean indicating whether the
 navigation controller in the application should be updated when displaying popups
 @agssince{2.0, 10.2}
 */
-(id)initWithPopupInfo:(AGSPopupInfo*)popupInfo graphic:(AGSGraphic*)graphic usingNavigationControllerStack:(BOOL)usingNavigationControllerStack;

/** Initializes an AGSPopupsContainerViewController with an AGSWebMap and an AGSGraphic.
 The feature must belong to the graphics collection of an AGSFeatureLayer.
 @param webmap containing the popup definition
 @param feature for which to display the popup
 @param usingNavigationControllerStack A boolean indicating whether the
 navigation controller in the application should be updated when displaying popups
 @agssince{2.0, 10.2}
 */
-(id)initWithWebMap:(AGSWebMap*)webmap forFeature:(AGSGraphic*)feature usingNavigationControllerStack:(BOOL)usingNavigationControllerStack;

#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)

@interface AGSPopupsContainerViewController : NSViewController <AGSPopupsContainer>

/** Initializes an AGSPopupsContainerViewController with an AGSPopupInfo and an AGSGraphic.
 The feature must belong to the graphics collection of an AGSFeatureLayer.
 @param popupInfo representing the popup definition
 @param graphic for which to display the popup
 @agssince{2.0, 10.2}
 */
-(id)initWithPopupInfo:(AGSPopupInfo*)popupInfo graphic:(AGSGraphic*)graphic;

/** Initializes an AGSPopupsContainerViewController with an AGSWebMap and an AGSGraphic.
 The feature must belong to the graphics collection of an AGSFeatureLayer.
 @param webmap containing the popup definition
 @param feature for which to display the popup
 @agssince{2.0, 10.2}
 */
-(id)initWithWebMap:(AGSWebMap*)webmap forFeature:(AGSGraphic*)feature;

/** Cancels the editing process for the currently shown popup.
 @agssince{2.0, 10.2}
 */
-(void)cancelEditingCurrentPopup;

#endif

/** The delegate to be notified when a user interacts with the popups or
 edits graphics related to the popups. The delegate class
 must adopt the @c AGSPopupsContainerDelegate protocol.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, weak) id<AGSPopupsContainerDelegate> delegate;

/**
 The popups to be displayed.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, copy) NSArray *popups;

/** Indicates whether the view controller is in the process of editing a feature.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, assign, readonly) BOOL inEditingMode;

/** When in edit mode and geometry editing is allowed, this property 
 returns a mutable geometry that you can edit and when editing is finished, it will 
 be set on the current popup's graphic.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSGeometry *currentEditingGeometry;

/** The current popup that is being viewed.
 @agssince{2.0, 10.2}
 */
@property (nonatomic, strong, readonly) AGSPopup *currentPopup;

/** Initializes an AGSPopupsContainerViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @agssince{2.0, 10.2}
 */
-(id)initWithPopups:(NSArray *)popups;

/**
 Update the view controller to display additional popups. This is useful
 when the view controller is already displaying some popups,
 but you then want to display additional popups that were retrieved in the
 background, for example, as part of a query/identify operation.
 @param popupInfos An array of @c AGSPopup objects representing the additional popups to be displayed
 @agssince{2.0, 10.2}
 */
-(void)showAdditionalPopups:(NSArray *)popupInfos;

/** Start the editing process for the currently shown popup.
 @agssince{2.0, 10.2}
 */
-(void)startEditingCurrentPopup;

/** Clears all the popups currently being shown. This is useful if you want to reuse an
 existing popups container to display an entirely new set of popups. That way,
 the popups container doesn't have to reload from a NIB 
 everytime it is shown.
 @agssince{2.0, 10.2}
 */
-(void)clearAllPopups;


@end

