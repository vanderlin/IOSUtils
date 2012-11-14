//
//  AppUtils.h
//  Flipper
//
//  Created by Todd Vanderlin on 4/25/12.
//  Copyright (c) 2012 Interactive Design. All rights reserved.
//

#import <Foundation/Foundation.h>


#ifndef PI
#define PI       3.14159265358979323846
#endif

#ifndef TWO_PI
#define TWO_PI   6.28318530717958647693
#endif

#ifndef M_TWO_PI
#define M_TWO_PI   6.28318530717958647693
#endif

#ifndef FOUR_PI
#define FOUR_PI 12.56637061435917295385
#endif

#ifndef HALF_PI
#define HALF_PI  1.57079632679489661923
#endif

#ifndef DEG_TO_RAD
#define DEG_TO_RAD (PI/180.0)
#endif

#ifndef RAD_TO_DEG
#define RAD_TO_DEG (180.0/PI)
#endif

#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

#ifndef CLAMP
#define CLAMP(val,min,max) (MAX(MIN(val,max),min))
#endif

#ifndef ABS
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif

@interface AppUtils : NSObject

+ (CGFloat) map:(CGFloat)value 
       inputMin:(CGFloat)inputMin 
       inputMax:(CGFloat)inputMax 
      outputMin:(CGFloat)outputMin
      outputMax:(CGFloat)outputMax
          clamp:(BOOL)clamp;

+ (CGFloat)clamp:(CGFloat)value min:(CGFloat)min max:(CGFloat)max;
+ (CGFloat)random:(CGFloat)max;
+ (CGFloat)random:(CGFloat)x y:(CGFloat)y;
+ (UIColor*)randomColor;
+ (NSString*)upperCaseFirstLetter:(NSString*)word;

@end