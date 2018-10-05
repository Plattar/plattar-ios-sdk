//
//  PlattarCVSession.h
//  PlattarSDK
//
//  Created by David Arayan on 4/5/18.
//  Copyright © 2018 Plattar. All rights reserved.
//

#ifndef PlattarCVSession_h
#define PlattarCVSession_h

#import <Foundation/Foundation.h>
#import "PlattarSettings.h"

@interface PlattarCVSession : NSObject

/**
 * These functions are deprecated and will be removed in a future release.
 * Use initPlattarView and isARSupported instead
 */
+ (id) initNativeWithSettings:(PlattarSettings*)settings;
+ (BOOL) isNativeARSupported;

/**
 * Initialise the main Plattar View Instance.
 */
+ (id) initPlattarView;
+ (BOOL) isARSupported;
    
+ (BOOL) isSimulator;

@end


#endif /* PlattarCVSession_h */
