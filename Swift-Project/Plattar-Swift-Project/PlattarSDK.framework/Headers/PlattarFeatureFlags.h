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

#define PLATTAR_FEATUREFLAG_API_QUERY @"%@/api/v2/application/%@"

@interface PlattarFeatureFlags : NSObject

+ (instancetype)getInstance;
- (BOOL)containsFlag:(NSString*)flag;
- (void)put:(NSString*)flag;
- (void)clear;
- (void)sync:(NSString*)baseURL applicationID:(NSString*)applicationID;
- (void)syncCallback:(void (^)(void)) completeCallback;
- (void)print;
- (NSString*)toJson;

@end

#endif /* PlattarFeatureFlags_h */
