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
#import <UIKit/UIKit.h>
#import "PlattarSettings.h"

/**
 * Allows navigating the web using the Plattar View.
 * NOTE: new instances of this interface shares the same
 * internal navigation instance.
 *
 * NOTICE: This is a non-secure context. Critical form data such
 * as passwords should not be used. Plattar injects it's own Javascript
 * contexts which is required to launch and view AR via the Web SDK's.
 *
 * This interface is thread safe.
 */
@interface PlattarNavigator : NSObject

/**
 * Used internally to create the Navigator instance. This should not be
 * called outside of the Plattar SDK. The context changes depending on the
 * settings of the Plattar SDK.
 */
- (instancetype) initWithContext:(id)context;

/**
 * Reload the current page. This will clear
 * all context data.
 */
- (void) reload;

/**
 * Go to the current URL. Depending on the
 * internet connection this may take some time (like all browsers)
 */
- (void) goTo:(NSString*)url;

/**
 * Checks if the current navigated
 * page supports Augmented Reality. Only returns
 * yes if the Plattar Web SDK was used to build the AR
 * experience. This can be used to launch the ARKit backend
 * and view the experience.
 */
- (BOOL) isARSupported;

/**
 * A Transparent view is required to be able to see the camera/world
 * view and overlay the AR content. use the setOpaque to revert the
 * transparency setting for a normal browsing experience.
 */
- (void) setTransparent;

/**
 * Normal browsing experience requires a non-transparent background. Use
 * this setting for all non-AR pages.
 */
- (void) setOpaque;

/**
 * Sets a custom background color for the Web View.
 */
- (void) setBackgroundColor:(UIColor*)color;

/**
 * Clear the current Cache. Next request
 * will re-download all data.
 */
- (void) clearCache;

/**
 * Check if this instance of the navigator is valid
 * Depending on the state of the SDK, the navigator instance
 * can become invalid. In an invalid state, no functionality
 * will work.
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

/**
 * Adds the current view instance into the provided parent view.
 * Note that if the current view was part of another view hierarchy
 * it will be popped before adding to the provided view.
 * Use this when the SDK is in a paused/hidden state but normal viewing
 * is still required.
 *
 * Adding this view into another parent view will force the current view
 * to resize to the same size as the parent view and automatically add
 * any required constraints.
 *
 * The AR viewport will always use the same size as the current view's size
 * when the AR component is launched.
 */
- (void) addToParentView:(UIView*)view;

/**
 * Removes the current view instance from it's parent view (if any)
 */
- (void) removeFromParentView;

@end

#endif /* PlattarNavigator_h */
