//
//  PlattarSDKFramework.h
//  PlattarSDKFramework
//
//  Created by Plattar on 17/05/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for PlattarSDK.
FOUNDATION_EXPORT double PlattarSDKFrameworkVersionNumber;

//! Project version string for PlattarSDK.
FOUNDATION_EXPORT const unsigned char PlattarSDKFrameworkVersionString[];

/*
 * All required imports by the Plattar System. Just #import <PlattarSDK/PlattarSDK.h>
 * to gain access to all public functionality of Plattar.
 */
#import <PlattarSDK/PlattarPermission.h>
#import <PlattarSDK/ConnectionChecker.h>
#import <PlattarSDK/Timer.h>
#import <PlattarSDK/PlattarUtil.h>
#import <PlattarSDK/PlattarWebEvent.h>
#import <PlattarSDK/PlattarSettings.h>
#import <PlattarSDK/PlattarFeatureFlags.h>
#import <PlattarSDK/PlattarCVSession.h>
#import <PlattarSDK/PlattarEngine.h>
