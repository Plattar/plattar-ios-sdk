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
 * Initialise the main Plattar View Instance.
 */
+ (id) initPlattarView;
+ (BOOL) isARSupported;
+ (BOOL) isMarkerARSupported;
+ (BOOL) isSimulator;

@end


#endif /* PlattarCVSession_h */
