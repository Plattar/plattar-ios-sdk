//
//  PlattarUtil.h
//  PlattarSDK
//
//  Created by Plattar on 23/05/2016.
//  Copyright © 2016 Plattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Defines Generic methods which allow for various useful operations.
 */
@interface PlattarUtil : NSObject

/**
 * This method will take a standard NSDictionary and generate
 * a valid JSON String to be sent over a network. Useful for communication or
 * passing data between client/server or app/ui.
 *
 * The Generated JSON is in UTF8 Format, so it will be readable
 */
+ (NSString*) dictToJSON :(NSDictionary*) dict;

/**
 * This method will take a standard NSDictionary and generate
 * a valid JSON String to be sent over a network. Useful for communication or
 * passing data between client/server or app/ui.
 *
 * The Generated JSON is in Base64 Format, the reciever will need to decode using Base64 to
 * get the readable format back.
 */
+ (NSString*) dictToJSON64 :(NSDictionary*) dict;

/**
 * This method will take a standard NSArray and generate
 * a valid JSON String to be sent over a network. Useful for communication or
 * passing data between client/server or app/ui.
 *
 * The Generated JSON is in UTF8 Format, so it will be readable
 */
+ (NSString*) arrToJSON :(NSArray*) array;

/**
 * This method will take a standard NSArray and generate
 * a valid JSON String to be sent over a network. Useful for communication or
 * passing data between client/server or app/ui.
 *
 * The Generated JSON is in Base64 Format, the reciever will need to decode using Base64 to
 * get the readable format back.
 */
+ (NSString*) arrToJSON64 :(NSArray*) array;

/*
 * Converts a basic UTF8 JSON String into a Dictionary. Used to convert
 * commands from a web-service into easier managable Dictionary types.
 *
 * From UTF8 JSON String into NSDictionary
 */
+ (NSDictionary*) jsonToDict: (NSString*) json;

/*
 * Converts a basic UTF8 JSON String into an Array. Used to convert
 * commands from a web-service into easier managable Array types.
 *
 * From UTF8 JSON String into NSDictionary
 */
+ (NSArray*) jsonToArray: (NSString*) json;

/*
 * Converts a basic Base64 Encoded JSON String into a Dictionary. Used to convert
 * commands from a web-service into easier managable Dictionary types.
 *
 * From Base64 Encoded JSON String into NSDictionary
 */
+ (NSDictionary*) json64ToDict: (NSString*) json;

/**
 * Send an async request ignoring HTTPS Cert status and return an NSDictionary of the parsed
 * JSON Data.
 */
+ (void) sendAsyncRequest: (NSString*)url withCallback: (void (^)(NSDictionary *jsonData)) callback;

/**
 * Given an image from a URL, download the image and return as a UIImage
 */
+ (UIImage *) getImageFromURL:(NSString*) fileURL;

/**
 * Given a JSON deom a URL, download the JSON data and return as an NSDictionary
 */
+ (NSDictionary *)getJSONFromURL:(NSString*) fileURL;

/**
 * Save a JPEG image into an easilly accessible cache directory
 */
+ (void) saveJPGImage:(UIImage *)image withFileName:(NSString *) imageName;
+ (UIImage *) loadJPGImage:(NSString *)fileName;
+ (UIImage *) loadJPGImageBundled: (NSString*)fileName;
+ (UIImage *) loadImageBundled: (NSString*)fileName;
+ (NSDictionary *) loadJSONBundled: (NSString*)fileName;
+ (void) errorNotify:(NSString*)msg;

/**
 * Convert an Image into its JPEG variant while Base64 Encoding. Useful if an image needs to be 
 * POSTed to some HTTP endpoint.
 */
+ (NSString*) convertImageToBase64JPEG:(UIImage*)data;

/**
 * Provided an Image and a startX/startY positions with width and height, crop the image and return
 * the cropped image (which will be a new instance).
 */
+ (UIImage*) cropImage:(UIImage*)data startX:(int)startX startY:(int)startY width:(int)width height:(int)height;

/**
 * Using a POST Async Request, send the provided image into the provided URL. The Response will be made to the provided
 * Callback function/block
 */
+ (void) sendAsyncImageRequest:(NSString*)url
                     withImage:(UIImage*)image
                  withCallback:(void (^)(NSDictionary *jsonData)) callback;

+ (void) sendAsyncImageRequestWithParams:(NSString*)url
                               withImage:(UIImage*)image
                                  params:(NSDictionary*)params
                            withCallback:(void (^)(NSDictionary *jsonData)) callback;

/**
 * Returns a String representation of the current device type
 */
+ (NSString*) getDeviceType;

/**
 * Check if the current device (using getDeviceType) matches the requested device (target)
 */
+ (BOOL) isDevice:(NSString*)target;

@end
