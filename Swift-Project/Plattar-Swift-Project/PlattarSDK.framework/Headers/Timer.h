//
//  Timer.h
//  PlattarSDK
//
//  Created by Plattar on 14/2/17.
//  Copyright © 2017 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Defines Generic methods which allow for various useful operations.
 */
@interface Timer : NSObject

+ (void) start:(NSString*)timerName;
+ (NSTimeInterval) stop:(NSString*)timerName;

@end
