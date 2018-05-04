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
#import <UIKit/UIKit.h>
#import "PlattarApplication.h"
#import "PlattarSettings.h"
#import "PlattarAppKeys.h"

@interface PlattarCVSession : NSObject

+ (id) initNativeWithSettings:(PlattarSettings*)settings;
+ (BOOL) isNativeARSupported;
+ (id) initKudanWithSettings:(PlattarSettings*)settings keys:(PlattarAppKeys *)keys;
+ (BOOL) isKudanARSupported;

@end


#endif /* PlattarCVSession_h */
