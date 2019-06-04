//
//  AppBridge.h
//  PlattarSDK
//
//  Created by David Arayan on 3/6/19.
//  Copyright © 2019 Plattar. All rights reserved.
//

#ifndef PlattarAppBridge_h
#define PlattarAppBridge_h

#import <Foundation/Foundation.h>
#import "PlattarSettings.h"

#define PLATTAR_OBJECT_QUERY @"%@/api/v2/application/%@/%@?filter[title]=%@"

@interface PlattarID : NSObject

- (instancetype) initWith:(NSString*)objectType uuid:(NSString*)uuid;
- (bool)isValid;
- (NSString*)objectType;
- (NSString*)uuid;

@end

@interface PlattarAppBridge : NSObject

- (instancetype) initWith:(id)stackInstance settings:(PlattarSettings*)settings;
- (void) open:(PlattarID*)pid;
- (void) openScene:(NSString*)uuid;
- (void) openSceneByName:(NSString*)name;
- (void) openPage:(NSString*)uuid;
- (void) openPageByName:(NSString*)name;
- (void) openApplication:(NSString*)uuid;
- (void) findSceneByName:(NSString*)name callback:(void (^)(NSArray *arr))completeCallback;
- (void) findPageByName:(NSString*)name callback:(void (^)(NSArray *arr))completeCallback;

@end

#endif
