//
//  EMMatrix4f.h
//  EzyMath
//
//  Created by Plattar on 25/11/16.
//  Copyright © 2016 Ezy. All rights reserved.
//

#ifndef EMMatrix4f_h
#define EMMatrix4f_h

#import <Foundation/Foundation.h>

@interface EMMatrix4f : NSObject

@property (nonatomic) float m00;
@property (nonatomic) float m01;
@property (nonatomic) float m02;
@property (nonatomic) float m03;

@property (nonatomic) float m10;
@property (nonatomic) float m11;
@property (nonatomic) float m12;
@property (nonatomic) float m13;

@property (nonatomic) float m20;
@property (nonatomic) float m21;
@property (nonatomic) float m22;
@property (nonatomic) float m23;

@property (nonatomic) float m30;
@property (nonatomic) float m31;
@property (nonatomic) float m32;
@property (nonatomic) float m33;

+ (id) create;

- (id) init;
- (id) initWithMat:(EMMatrix4f*)mat;
- (id) initWithArr:(const float[])arr;

- (EMMatrix4f*) rotateX:(float)angle;
- (EMMatrix4f*) rotateY:(float)angle;
- (EMMatrix4f*) rotateZ:(float)angle;

+ (EMMatrix4f*) mul:(EMMatrix4f*)mat1 with:(EMMatrix4f*)mat2;
+ (EMMatrix4f*) mulDst:(EMMatrix4f*)left with:(EMMatrix4f*)right dest:(EMMatrix4f*)dest;

- (EMMatrix4f*) zero;
- (EMMatrix4f*) identity;
- (EMMatrix4f*) copy;
- (EMMatrix4f*) copyFrom:(EMMatrix4f*)mat;
- (EMMatrix4f*) copyFromArray:(const float[])arr;
- (EMMatrix4f*) inv;
- (EMMatrix4f*) swapCoordinateSystem;
- (float) det;
- (NSArray*) arr:(NSMutableArray*)array;
- (void) print;

@end

#endif /* EMMatrix4f_h */
