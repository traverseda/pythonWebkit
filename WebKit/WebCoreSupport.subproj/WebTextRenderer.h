/*	
    WebTextRenderer.h  
    Copyright 2002, Apple, Inc. All rights reserved.
*/

#import <WebCore/WebCoreTextRenderer.h>

typedef struct WidthMap WidthMap;
typedef struct WidthEntry WidthEntry;
typedef struct GlyphMap GlyphMap;
typedef struct GlyphEntry GlyphEntry;
typedef struct UnicodeGlyphMap UnicodeGlyphMap;
typedef struct SubstituteFontWidthMap SubstituteFontWidthMap;

/// Should be more than enough for normal usage.
#define NUM_SUBSTITUTE_FONT_MAPS	10

@interface WebTextRenderer : NSObject <WebCoreTextRenderer>
{
    int ascent;
    int descent;
    int lineSpacing;
    ATSGlyphRef spaceGlyph;
    
    ATSStyleGroupPtr styleGroup;
    
@public
    NSFont *font;
    GlyphMap *characterToGlyphMap;			// Used for 16bit clean unicode characters.
    UnicodeGlyphMap *unicodeCharacterToGlyphMap; 	// Used for surrogates.
    WidthMap *glyphToWidthMap;
    float spaceWidth;
    float ceiledSpaceWidth;
    float roundedSpaceWidth;
    float adjustedSpaceWidth;

    int numSubstituteFontWidthMaps;
    int maxSubstituteFontWidthMaps;
    SubstituteFontWidthMap *substituteFontWidthMaps;
    
@private
    BOOL usingPrinterFont;
}

+ (BOOL)shouldBufferTextDrawing;

- (id)initWithFont:(NSFont *)font usingPrinterFont:(BOOL)usingPrinterFont;

- (float)_floatWidthForCharacters:(const UniChar *)characters stringLength:(unsigned)stringLength fromCharacterPosition:(int)pos numberOfCharacters:(int)len withPadding:(int)padding applyRounding:(BOOL)applyRounding attemptFontSubstitution:(BOOL)attemptSubstitution widths:(float *)widthBuffer fonts:(NSFont **)fontBuffer glyphs:(CGGlyph *)glyphBuffer numGlyphs:(int *)_numGlyphs letterSpacing:(int)ls wordSpacing:(int)ws smallCaps:(BOOL)smallCaps fontFamilies:(NSString **)families;

@end
