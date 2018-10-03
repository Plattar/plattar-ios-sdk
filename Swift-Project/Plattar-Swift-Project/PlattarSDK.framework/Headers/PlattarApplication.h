//
//  PlattarApplication.m
//  PlattarSDK
//
//  Created by Plattar on 11/05/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlattarWebEvent.h"

/**
 * The primary interface which the user should interact with.
 */
@protocol PlattarApplication <NSObject>

@required

/**
 * Start the Plattar system and all submodules, making it ready
 * for AR rendering. This is a fairly expnsive operation and the system starts
 * up on another thread. This is to avoid freezing the execution of the main application.
 */
- (void) start;

/**
 * Pause the Plattar system and all submodules, resume() will be required
 * to contonue execution. This event can also be fired by the OS system (ie:
 * when the app is minimized).
 */
- (void) pause;

/**
 * Resume the Plattar system and all submodules, this can be called if the system
 * was paused using pause() function. This event can also be fired by the OS system (ie:
 * when the app is maximized or re-gains focus).
 */
- (void) resume;

/**
 * Destroy the system and clean up the garbage, freeing up system resources for other uses. This
 * is a fairy expensive operation and should be used cautiously.
 */
- (void) destroy;

/**
 * Get the primary UIViewController used for viewing internal components. The view should be dispalyed
 * by the primary application.
 */
- (UIViewController*) getController;

/**
 * Register for Events fired from the WebGL Renderer and the Controller
 * UI Template from Plattar. All Possible events are defined in the WebEvent
 * enum @ PlattarWebEvent.h.
 *
 * This performs a direct O(1) Mapping between the provided function and the fired
 * web event. The provided method must accept an NSDictionary* as an argument.
 *
 * This function will map the arguments internally to a dedicated event controller
 *
 * SAMPLE USE
 * [mainView registerForEvent:onWebGLReady :@selector(myCustomReciever:) :self];
 */
- (void) registerForEvent: (WebEvent) event callbackSelector:(SEL) selector instanceClass:(Class) impl;

/**
 * Register for Events fired from the WebGL Renderer and the Controller
 * UI Template from Plattar. All Possible events are defined in the WebEvent
 * enum @ PlattarWebEvent.h.
 *
 * This performs a direct O(1) Mapping between the providedblock and the fired
 * web event. The provided block must accept an NSDictionary* as an argument.
 *
 * This function will map the arguments internally to a dedicated event controller
 *
 * SAMPLE USE
 * [mainView registerForEventCallback:onWebGLReady withCallback:^(event){}];
 */
- (void) registerForEventCallback: (WebEvent) event withCallback:(void (^)(NSDictionary*)) callback;

/**
 * Evaluate and Execute the provided Javascript function in the current loaded template. The system will also
 * use the same function for performing callbacks on critical events that may occur.
 */
- (void) evalJS: (NSString*) js;

/**
 * Resets the UI to its original URL (if any). Use this if external links get you lost or something.
 */
- (void) resetUI;
 
@end
