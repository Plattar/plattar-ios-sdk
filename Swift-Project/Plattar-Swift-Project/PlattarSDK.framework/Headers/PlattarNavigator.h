//
//  PlattarNavigator.h
//  PlattarSDK
//
//  Created by David Arayan on 2/11/18.
//  Copyright © 2018 Plattar. All rights reserved.
//

#ifndef PlattarNavigator_h
#define PlattarNavigator_h

#import <Foundation/Foundation.h>
#import "PlattarSettings.h"

/**
 * Allows navigating the web using the Plattar View.
 * NOTE: new instances of this interface shares the same
 * internal navigation instance.
 *
 * This interface is thread safe.
 */
@interface PlattarNavigator : NSObject

- (instancetype) initWithContext:(id)context;

/**
 * Reload the current page
 */
- (void) reload;

/**
 * Go to the current URL
 */
- (void) goTo:(NSString*)url;

/**
 * Clear the current Cache. Next request
 * will re-download all data.
 */
- (void) clearCache;

/**
 * Check if this instance of the navigator is valid
 */
- (BOOL) isValid;

/**
 * Checks if the provided URL is a plattar app
 * URL. Returns true if the URL is able to be loaded
 * as a Plattar app.
 */
+ (BOOL) checkAppURL:(NSString*)url;

/**
 * Generate the dynamic settings from the provided
 * plattar app URL. If the application cannot be found
 * this method will return nil.
 *
 * The settings can be used to initialise the Plattar SDK
 * and load in a brand new app.
 */
+ (void) getSettingsFrom:(NSString*)url withCallback:(void (^)(PlattarSettings *jsonData)) callback;

@end


#endif /* PlattarNavigator_h */
