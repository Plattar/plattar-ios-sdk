//
//  PlattarFeatureFlags.h
//  PlattarSDK
//
//  Created by David Arayan on 26/9/17.
//  Copyright © 2017 Plattar. All rights reserved.
//

#ifndef PlattarFeatureFlags_h
#define PlattarFeatureFlags_h

#import <Foundation/Foundation.h>

@interface PlattarFeatureFlags : NSObject

+ (instancetype)getInstance;
- (BOOL)containsFlag:(NSString*)flag;
- (void)put:(NSString*)flag;
- (void)clear;

@end

#endif /* PlattarFeatureFlags_h */
