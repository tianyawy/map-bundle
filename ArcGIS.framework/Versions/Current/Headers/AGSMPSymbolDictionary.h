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

@class AGSMPSymbolDictionaryQuery;

/** @file AGSMPSymbolDictionary.h */ //Required for Globals API doc

/** @brief A symbol dictionary object.
 
 The SymbolDictionary class contains functionality to get
 information about the dictionary including lists of symbols
 and their associated information.
 
 @define{AGSMPSymbolDictionary.h, ArcGIS}
 @agssince{10.1.1, 10.2}
  @see @c AGSMPMessageProcessor
 */
@interface AGSMPSymbolDictionary : NSObject {
}

/** The set of available filter names for this symbol dictionary.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy, readonly) NSSet* filterNames;

/** The set of available keywords for this symbol dictionary.
 @agssince{10.1.1, 10.2}
 */
@property (nonatomic, copy, readonly) NSSet* keywords;

/** Initialize the symbol dictionary.
 @param type The symbol dictionary type.
 @return A new message processor object.
 @agssince{10.1.1, 10.2}
 */
- (id)initWithSymbolDictionaryType:(AGSMPSymbolDictionaryType)type;

/** Initialize the symbol dictionary.
 @param type The symbol dictionary type.
 @param path The path to the dictionary file on the device.
 @return A new message processor object.
 @agssince{10.1.1, 10.2}
 */
- (id)initWithSymbolDictionaryType:(AGSMPSymbolDictionaryType)type resourcePath:(NSString*)path;

/** Returns the set of possible values for @p filterName.
 @param filterName The name of the desired filter.
 @agssince{10.1.1, 10.2}
 */
- (NSSet*)valuesForFilter:(NSString*)filterName;

/** Returns the image swatch for @p symbolName. 
 @param symbolName The name of the symbol to get the swatch from.
 @agssince{10.1.1, 10.2}
 */
- (AGSImage*)swatchForSymbol:(NSString*)symbolName;

/** Returns the set of available keywords for @p symbolName. 
 @param symbolName The name of the symbol to get the keywords for.
 @agssince{10.1.1, 10.2}
 */
- (NSSet*)keywordsForSymbol:(NSString*)symbolName;

/** Returns the set of symbol names corresponding to @p query for this symbol dictionary. 
 @param query The query used to search the symbol names.
 @agssince{10.1.1, 10.2}
 */
- (NSSet*)namesForQuery:(AGSMPSymbolDictionaryQuery*)query;

/** Returns the available values for Category, SymbolId and StyleFile for @p symbolName. 
 @param symbolName The name of the symbol to get the values for.
 @agssince{10.1.1, 10.2}
 */
- (NSDictionary*)valuesForSymbol:(NSString*)symbolName;

@end
