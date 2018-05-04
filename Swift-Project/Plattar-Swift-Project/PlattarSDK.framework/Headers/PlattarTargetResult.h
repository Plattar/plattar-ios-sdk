//
//  PlattarTargetResult.h
//  PlattarSDK
//
//  Created by Plattar on 29/04/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * This converts from a C++ Class into a format that Obj-C
 * can understand. C++ Does not work well with @protocol types
 *
 * This object contains critical information about the current marker which
 * is being tracked. This result is returned by the Plattar System and can be
 * used for extra application logic (if required).
 */
@interface PlattarTargetResult : NSObject

/*
 * Called by the Plattar system when new data is available. Original information
 * comes from a C/C++ layer (which is then converted into Objective-C stuff).
 */
- (id) initWithResult :(const char*) rMetaData
                      :(const char*) rTargetName
                      :(const float) rTargetSize
                      :(const char*) rUniqueID;

/*
 * Returns the size of the target as it's defined in the cloud. This is used
 * to normalize the augmentation size so it matches the one in the CMS.
 */
- (float) getTargetSize;

/*
 * Returns the name of the current target as it's defined in the Plattar CMS. The name
 * is non-unique.
 */
- (NSString*) getTargetName;

/*
 * Returns the unique target ID (mix of numeric/caharcter) values which is unique for this
 * particular project. This is primarily used for unique DB searches on the Plattar system, but can
 * also be used to uniquely identify certain markers.
 */
- (NSString*) getTargetID;

@end