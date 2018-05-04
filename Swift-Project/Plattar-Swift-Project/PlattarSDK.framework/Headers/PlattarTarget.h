//
//  PlattarTarget.h
//  PlattarSDK
//
//  Created by Plattar on 29/04/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EMMatrix4f.h"

/**
 * Returns Pose information about the current tracker. These values are updated
 * on a set timer defined by the Plattar System. It is advised to register and listen
 * to the appropriate callback which will be called repeatedly. 
 *
 * The POSE information is used by the Plattar renderer to position and display 3D content
 * properly. It can also be used for an external renderer (such as openGL ES/Metal etc..) to
 * do your own rendering.
 *
 * Contains Helper functions via xxxFill() methods which allows adding the internal matrix data
 * into a dictionary (as an array) for easy serialization or transfer over a network.
 */
@interface PlattarTarget : NSObject

/**
 * Called by the Plattar system when new data is available. Original information
 * comes from a C/C++ layer (which is then converted into Objective-C stuff).
 */
- (id) initWithResult :(const float[]) poseMatrix
                      :(int) poseMatrixSize
                      :(const float[]) mvMatrix
                      :(int) mvMatrixSize
                      :(const float[]) projection
                      :(int) projectionSize;

/**
 * Access the data in the current Model-View Matrix by index. The Model-View Matrix
 * is calculated from the current Pose Matrix of the Tracker.
 */
- (EMMatrix4f*) getMvMatrix;

/**
 * Returns the complete Model-View Matrix in an NSArray form. Matrix data are floating
 * point values accessed via NSNumber.
 */
- (NSArray*) getMvMatrixArray;

/**
 * Access the data in the current Pose Matrix which is used for rendering
 * augmentations. Use this for your own calculations (if you understand it), otherwise
 * you should use the pre-calculated Model-View Matrix (already done for you).
 */
- (EMMatrix4f*) getPoseMatrix;

/**
 * Returns the complete Pose Matrix in an NSArray form. Matrix data are floating
 * point values accessed via NSNumber.
 */
- (NSArray*) getPoseMatrixArray;

/*
 * Access the data in the current Projection Matrix. This matrix can change if
 * the phone is rotated to landscape/portrait mode for example.
 */
- (EMMatrix4f*) getProjMatrix;

/**
 * Returns the complete Projection Matrix in an NSArray form. Matrix data are floating
 * point values accessed via NSNumber.
 */
- (NSArray*) getProjMatrixArray;

/*
 * Access the data in the current Model-View * Projection Matrix. This Matrix will
 * only be calculated if it's needed, to save performance..
 */
- (EMMatrix4f*) getMvProjMatrix;

/**
 * Returns the complete Model-View-Projection Matrix in an NSArray form. Matrix data are floating
 * point values accessed via NSNumber.
 */
- (NSArray*) getMvProjMatrixArray;

@end
