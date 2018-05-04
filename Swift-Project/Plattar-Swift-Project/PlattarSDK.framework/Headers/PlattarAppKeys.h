//
//  PlattarAppKeys.h
//  PlattarSDK
//
//  Created by Plattar on 26/04/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * Easy storage of all required Keys for PlattarSDK. These keys
 * can be dynamic and fetched from the API if required (before init)
 */
@interface PlattarAppKeys : NSObject

/*
 * The Vuforia License Key for the App (need defaults?)
 */
@property (nonatomic, readwrite) NSString *appKey;

/*
 * The Vuforia Cloud Access Key (need defaults?)
 */
@property (nonatomic, readwrite) NSString *cloudAccessKey;

/*
 * The Vuforia Cloud Secret Key (need defaults?)
 */
@property (nonatomic, readwrite) NSString *cloudSecretKey;

/*
 * Generate internal data with one go. (make internal variables private?)
 */
- (void) setKeys:(NSString* ) mAppKey
                :(NSString* ) mCloudAccessKey
                :(NSString* ) mCloudSecretKey;

/*
 * Convert from internal NSString to raw C char array and return
 */
- (const char*) getAppKeyRaw;
- (const char*) getCloudAccessKeyRaw;
- (const char*) getCloudSecretKeyRaw;

- (void) printAccessKey;

@end
