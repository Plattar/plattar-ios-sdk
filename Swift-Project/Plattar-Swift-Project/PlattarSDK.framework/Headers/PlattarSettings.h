//
//  PlattarSettings.h
//  PlattarSDK
//
//  Created by Plattar on 22/06/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Public Constant Values for generating the settings via efficient
 * bit flags.
 */
static NSString *PLATTAR_DEFAULT_URL       = @"https://www.plattar.com";
static NSInteger PLATTAR_AUTO_START        = 1 >> 1;
static NSInteger PLATTAR_TEMPLATE_DESTROY  = 1 >> 2;
static NSInteger PLATTAR_TEMPLATE_BLOCKED  = 1 >> 3;
static NSInteger PLATTAR_DEBUG_ENABLED     = 1 >> 4;

/**
 * PlattarSettings can be used to customize the launch of the main Plattar App.
 */
@interface PlattarSettings : NSObject

/**
 * Init using default values for all - See The Constant Values for the defaults.
 * All Defaults will be set to bit-0;
 */
- (id) init;

/**
 * Init using a provided Base64 Encoded Key. The Key is not encoded and is publically available.
 * Contents can be seen by using Base64 Decoding. Plattar will decode and fill in the settings
 * accordingly. Overrides can be done via standard function calls after init.
 */
- (id) initWithKeyString: (NSString*) key;

/**
 * Primarily used as a direct copy-constructor. Plattar will copy the settings once it's inserted
 * into the PlattarApplication, this is to avoid changing the settings at runtime, especially from
 * different threads. Use the provided PlattarApplication interface to interface after init.
 */
- (id) initWithSettings: (PlattarSettings*) settings;

/**
 * Init using the Bit-Key constants provided as part of the PlattarSettings.h file.
 * Usage Example. NSInteger key = PLATTAR_AUTO_START | PLATTAR_TEMPLATE_DESTROY | PLATTAR_TEMPLATE_BLOCKED;
 */
- (id) initWithKeyInt: (NSInteger) key;

- (void) setAutoStart: (BOOL) autostart;
- (void) setTemplateUrl: (NSString*) url;
- (void) setDestroyTemplateOnDestroy: (BOOL) destroyTemplate;
- (void) setBlockTemplateControl: (BOOL) blockTemplate;
- (void) setDebugEnabled: (BOOL) isDebugEnabled;

- (BOOL) getAutoStart;
- (NSString*) getTemplateUrl;
- (NSString*) getHostUrl;
- (NSString*) getApplicationID;
- (BOOL) getTemplateDestroy;
- (BOOL) getTemplateBlocked;
- (BOOL) getDebugEnabled;
- (NSString*) getTemplateCommand;

@end
