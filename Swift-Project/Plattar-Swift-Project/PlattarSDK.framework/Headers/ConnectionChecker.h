//
//  ConnectionChecker.h
//  PlattarSDK
//
//  Created by Plattar on 15/2/17.
//  Copyright © 2017 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Defines Generic methods which allow for various useful operations.
 */
@interface ConnectionChecker : NSObject

+ (BOOL) checkConnection;
+ (void) checkConnectionWithCallback:(void (^)(void)) successCallback failure:(void (^)(void)) failureCallback;
+ (void) showConnectionMessage;

@end
