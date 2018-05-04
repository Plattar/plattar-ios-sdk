//
//  PlattarCallback.m
//  PlattarSDK
//
//  Created by Plattar on 11/05/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PlattarTargetResult.h"
#import "PlattarTarget.h"

/*
 * Defines a set of functions which can be optionally implemented by the external
 * application to listen for the various events which may occur.
 *
 * These functions are optional, only the functions implemented will be called by the system.
 */
@protocol PlattarCallback <NSObject>

@optional

/*
 * Called from the internal update loop. This is varies depending on the maximal framerate
 * (TO-DO) add deltaTime for smooth logic.
 */
- (void) onARUpdate;

/*
 * Called from the internal render loop. This varies depending on the maximal framerate
 * and is called from the openGL layer. Does not guarantee sync with the Update Loop.
 */
- (void) onARRender;

/*
 * Called as soon as a new marker has been found and began tracking. Returns marker specific
 * information such as name, size and ID. Only called once as soon as a new marker tracking occurs.
 */
- (void) onMarkerFound: (PlattarTargetResult*) result;

/*
 * Function is called as soon as the system loses tracking of a previously tracked marker. Results
 * will be sent over and local reference will be reset.
 */
- (void) onMarkerLost: (PlattarTargetResult*) result;

/*
 * Called as soon as the current tracking marker updates its pose information. Contains matrix data
 * useful for rendering and/or performing other external app logic.
 */
- (void) onMarkerTracked: (PlattarTarget*) result;

@end
