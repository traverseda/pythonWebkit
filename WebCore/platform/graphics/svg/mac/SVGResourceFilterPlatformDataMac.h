/*
 * Copyright (C) 2007 Eric Seidel <eric@webkit.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef SVGResourceFilterPlatformDataMac_h
#define SVGResourceFilterPlatformDataMac_h

#if ENABLE(SVG) && ENABLE(SVG_EXPERIMENTAL_FEATURES)

#include "SVGResourceFilter.h"

#include <ApplicationServices/ApplicationServices.h>
#include <wtf/RetainPtr.h>

@class CIImage;
@class CIFilter;
@class CIContext;
@class NSArray;
@class NSMutableDictionary;

namespace WebCore {
    class SVGResourceFilterPlatformDataMac : public SVGResourceFilterPlatformData {
    public:
        SVGResourceFilterPlatformDataMac(SVGResourceFilter*);
        virtual ~SVGResourceFilterPlatformDataMac();
        
        CIImage* imageForName(const String&) const;
        void setImageForName(CIImage*, const String&);
        
        void setOutputImage(const SVGFilterEffect*, CIImage*);
        CIImage* inputImage(const SVGFilterEffect*);
        
        NSArray* getCIFilterStack(CIImage* inputImage, const FloatRect& bbox);
        
        CIContext* m_filterCIContext;
        CGLayerRef m_filterCGLayer;
        RetainPtr<NSMutableDictionary> m_imagesByName;
        SVGResourceFilter* m_filter;
    };
}

#endif // #if ENABLE(SVG) && ENABLE(SVG_EXPERIMENTAL_FEATURES)

#endif // SVGResourceFilterPlatformDataMac_h
