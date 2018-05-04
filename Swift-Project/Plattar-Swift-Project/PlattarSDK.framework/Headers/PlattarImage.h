//
//  PlattarImage.h
//  PlattarSDK
//
//  Created by Plattar on 20/09/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Used to work with complex images from different sources. Due to the complexity of the Plattar System, when requiring
 * a screen capture the System must take multiple screenshots, resize and merge them all into a single image. This class
 * provides an easy to use interface to the final images.
 */
@interface PlattarImage : NSObject

- (id) initBlank;
- (id) initWithImage:(UIImage*)img;
- (id) initWithImageData:(UIImage*)img withData:(GLubyte*)data;
- (id) initWithBase64String:(NSString*)img;

/**
 * Returns the internally compiled Image as a UIImage reference, which can be used to save/perform
 * other operations on.
 */
- (UIImage*) getImage;
- (float) getWidth;
- (float) getHeight;

/**
 * Returns true if the image is valid, otherwise will return false
 */
- (BOOL) isValid;

/**
 * Saves the current image into the users camera roll. Proper permissions must be granted for the operation.
 * UPDATE - As of Version 0.5 (SDK) this function will ask proper permissions (if not granted) by the user
 * before proceeding.
 */
- (void) saveIntoCameraRoll;

/**
 * Use this function to share the provided image using native share functionality
 */
- (void) share:(NSDictionary*)data parent:(UIViewController*)parent;

/**
 * Static function which allows combining multiple PlattarImage types into a single image/canvas and returned.
 */
+ (PlattarImage*) combineWithImage:(PlattarImage*)firstImage withImage:(PlattarImage*)secondImage;

@end
