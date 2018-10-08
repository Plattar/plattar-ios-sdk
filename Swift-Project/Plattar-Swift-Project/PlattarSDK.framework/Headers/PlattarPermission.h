//
//  PlattarPermission.h
//  PlattarSDK
//
//  Created by Plattar on 10/11/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface PlattarPermission : NSObject

+ (void) askCameraAccess:(void (^)(void)) callback denied:(void (^)(void)) denied;
+ (void) askPhotoAccess:(void (^)(void)) callback denied:(void (^)(void)) denied;
+ (void) askAccess:(void (^)(void)) callback denied:(void (^)(void)) denied;
+ (void) denyPhotoMessage;
+ (void) denyCameraMessage;

@end
