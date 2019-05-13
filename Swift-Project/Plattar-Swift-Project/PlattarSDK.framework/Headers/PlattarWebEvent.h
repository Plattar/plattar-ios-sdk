//
//  PlattarWebEvent.h
//  PlattarSDK
//
//  Created by Plattar on 30/05/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 * The type of events the JS layer can call
 */
typedef enum {
    onRequestSDKDeviceInfo = 0,
    onWebGLReady,
    onStartAREngine,
    onStopAREngine,
    onPauseAREngine,
    onResumeAREngine,
    onOpenExternalUrl,
    onRequestApplication,
    onEnableTriggers,
    onForceLoseTracking,
    onCaptureScreenshot,
    onStartMarkerless,
    onSendAnalytics,
    onStartMarkerlessPlacement,
    onScanMarker,
    onChangeApp,
    onWebUpdate,
    onScanTriggerSnap,
    onCaptureScreenshotShare,
    onStartQRScanner,
    onStopQRScanner,
    WebEventCount
} WebEvent;

/*
 * Used in converting the enum into Strings for certain debugging information
 */
#define WebEventArray @"onRequestSDKDeviceInfo", @"onWebGLReady", @"onStartAREngine", @"onStopAREngine", @"onPauseAREngine", @"onResumeAREngine", @"onOpenExternalUrl", @"onRequestApplication", @"onEnableTriggers", @"onForceLoseTracking", @"onCaptureScreenshot", @"onStartMarkerless", @"onSendAnalytics", @"onStartMarkerlessPlacement", @"onScanMarker", @"onChangeApp", @"onWebUpdate", @"onScanTriggerSnap", @"onCaptureScreenshotShare", @"onStartQRScanner", @"onStopQRScanner", nil

/*
 * Global Variables and Functions when dealing with the event enumerators.
 */
@interface PlattarWebEvent : NSObject

/*
 * Returns the number of available events or enums
 */
+ (int) getEventCount;

/*
 * Takes a String and performs a conversion to the native Enum Type. Used
 * by the web system to convert String Events which is part of a JSON into
 * the native events.
 */
+ (WebEvent) stringToEvent: (NSString*) event;

/*
 * Takes an Enum type and performs a conversion into its String representation. Used
 * mainly for debugging and/or dictionary key-value types.
 */
+ (NSString*) eventToString: (WebEvent) event;

@end
