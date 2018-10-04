//
//  PlattarEngine.h
//  PlattarSDK
//
//  Created by David Arayan on 1/10/18.
//  Copyright © 2018 Plattar. All rights reserved.
//

#ifndef PlattarEngine_h
#define PlattarEngine_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PlattarWebEvent.h"
#import "PlattarSettings.h"

/**
 * The primary engine interface. Note that all user actions such
 * as pause/resume/show/hide will always override automated behaviour
 * and automated behaviour will never override user actions. For
 * example, the app will not automatically resume when brought to the
 * forefront if the last user action was a pause() event.
 */
@protocol PlattarEngine <NSObject>

@required

/**
 * Setup the Plattar AR Engine and all routines. This will keep
 * things in a paused state. Use this initially if Augmented Reality
 * is required. This is an expensive process which will drain the
 * battery quickly. Use sparingly.
 */
- (void) setup:(PlattarSettings*)settings;

/**
 * This will setup and show the UI system for Plattar, which will
 * also initialise all rendering routines for Augmented Reality. Use
 * this to launch the full Plattar view Stack. This is an expensive
 * process which will drain the battery quickly. Use sparingly.
 */
- (void) start;

/**
 * Pauses the AR and Rendering/UI Engines. Engine will not
 * automatically resume. Use this operation if AR is not required
 * and the user would like to save some battery. This operation will
 * keep all UI/Rendering elements in memory.
 */
- (void) pause;

/**
 * Resumes the AR and UI/Rendering Engines. This will resume
 * operations from the previously paused state.
 */
- (void) resume;

/**
 * Returns the View responsible for rendering the 2D User Interface and
 * the 3D Augmented Reality view. This renderer runs on WebGL.
 */
- (UIView*) getContentView;

/**
 * Returns the View responsible for rendering the Camera/User's world.
 * This view will not update it's contents if the Camera is not running.
 */
- (UIView*) getCameraView;

/**
 * Returns the parent view which encapsulates the Content/Camera views
 * from Plattar. Use this view and push it on top of your current view
 * hierarchy.
 *
 * Resizing this view will also resize all child views accordingly. For
 * best results, the Parent view should be the same size as the current
 * device screen.
 */
- (UIView*) getParentView;

/**
 * Resize the current view to the provided CGSize. This will resize
 * the UI/Rendering views accordingly.
 */
- (void) resize:(CGSize)size;

/**
 * Resize the current view to the Retina Screen Size of the Device.
 * This will resize the UI/Rendering view accordingly.
 */
- (void) resizeToScreenSize;

/**
 * This will push the UI/Rendering Views on top of the current View
 * hierarchy and resume all operations.
 */
- (void) show;

/**
 * This will pop the UI/Rendering Views from the current View
 * hierarchy and pause all operations. Use this if you have your
 * own views on top of the Plattar view hierarchy which occludes/blocks
 * all visual elements. This operation will save some battery.
 */
- (void) hide;

/**
 * Destroy the AR and Rendering/UI Engines. This will deallocate all
 * previously allocated memory. Use this functionality if AR is no
 * longer required and the Engines will no longer be used. If
 * operations need to be resumed, the user must allocate and run
 * through the setup/start process again.
 */
- (void) destroy;

/**
 * Register for Events fired from the WebGL Renderer and the
 * Controller UI Template from Plattar. All Possible events are defined
 * in the WebEvent enum @ PlattarWebEvent.h.
 *
 * This performs a direct O(1) Mapping between the providedblock and the
 * fired web event. The provided block must accept an NSDictionary* as an
 * argument.
 *
 * This function will map the arguments internally to a dedicated event
 * controller
 *
 * SAMPLE USE
 * [mainView registerForEventCallback:onWebGLReady withCallback:^(event){}];
 */
- (void) registerForEventCallback:(WebEvent)event withCallback:(void (^)(NSDictionary*))callback;

@end

#endif
