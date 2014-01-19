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

// ----------------------------------------------------------------
static void printAllFonts() {
    for (NSString *familyName in [UIFont familyNames]) {
        for (NSString *fontName in [UIFont fontNamesForFamilyName:familyName]) {
            NSLog(@"%@", fontName);
        }
    }
}

// ----------------------------------------------------------------
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
+ (void)translateView:(UIView*)view position:(CGPoint)position;

+ (void)writeFile:(NSString *)fileName data:(id)data;
+ (NSString *)readFile:(NSString *)fileName;
+ (void)saveImageFromDocuments:(UIImage*)image withName:(NSString*)filename;
+ (UIImage*)loadImageFromDocuments:(NSString*)filename;
+ (BOOL)removeFileFromDocuments:(NSString *)fileName;
@end

@interface UIView (UIViewExtension)
-(void)translate:(CGPoint)position;
-(CALayer*)getSublayerNamed:(NSString*)name;
-(CGPoint) getTopRight;
-(CGPoint) getTopLeft;
-(CGPoint) getBottomRight;
-(CGPoint) getBottomLeft;

-(CGPoint) getMiddleRight;
-(CGPoint) getMiddleLeft;

-(CALayer*)addTopBorder:(UIColor*)color;
-(CALayer*)addBottomBorder:(UIColor*)color;
-(CALayer*)addRightBorder:(UIColor*)color;
-(CALayer*)addLeftBorder:(UIColor*)color;
-(void)removeLayerName:(NSString*)name;
-(void)setWidth:(CGFloat)width andHeight:(CGFloat)height;

@end
@implementation UIView (UIViewExtension)
-(void)translate:(CGPoint)position {
    CGRect r = self.frame;
    r.origin = position;
    self.frame = r;
}
-(CALayer*) getSublayerNamed:(NSString *)name {
    for(CALayer * ca in self.layer.sublayers) {
        if([ca.name isEqualToString:name]) return ca;
    }
    return nil;
}
-(void)removeLayerName:(NSString *)name {
    for(CALayer * ca in self.layer.sublayers) {
        if([ca.name isEqualToString:name]) [ca removeFromSuperlayer];
    }
}
-(CGPoint) getTopLeft {
    return CGPointMake(self.frame.origin.x, self.frame.origin.y);
}
-(CGPoint) getBottomLeft {
    return CGPointMake(self.frame.origin.x, self.frame.origin.y + self.frame.size.height);
}
-(CGPoint) getTopRight {
    return CGPointMake(self.frame.origin.x+self.frame.size.width, self.frame.origin.y);
}
-(CGPoint) getBottomRight {
    return CGPointMake(self.frame.origin.x+self.frame.size.width, self.frame.origin.y+self.frame.size.height);
}
-(CGPoint) getMiddleRight {
    return CGPointMake(self.frame.origin.x+self.frame.size.width, self.frame.origin.y+(self.frame.size.height/2));
}
-(CGPoint) getMiddleLeft {
    return CGPointMake(self.frame.origin.x, self.frame.origin.y+(self.frame.size.height/2));
}

-(CALayer*) addTopBorder:(UIColor*)color {
    CALayer * stroke = [CALayer layer];
    [stroke setName:@"top_border_stoke"];
    for(CALayer * ca in self.layer.sublayers) {
        if([ca.name isEqualToString:@"top_border_stroke"]) [ca removeFromSuperlayer];
    }
    stroke.frame = CGRectMake(0, 0, self.frame.size.width, 1);
    stroke.backgroundColor = color.CGColor;
    [self.layer addSublayer:stroke];
    return stroke;
}
-(CALayer*) addBottomBorder:(UIColor*)color {
    CALayer * stroke = [CALayer layer];
    [stroke setName:@"bottom_border_stoke"];
    for(CALayer * ca in self.layer.sublayers) {
        if([ca.name isEqualToString:@"bottom_border_stoke"]) [ca removeFromSuperlayer];
    }
    stroke.frame = CGRectMake(0, self.frame.size.height-1, self.frame.size.width, 1);
    stroke.backgroundColor = color.CGColor;
    [self.layer addSublayer:stroke];
    return stroke;
}
-(CALayer*) addRightBorder:(UIColor*)color {
    CALayer * stroke = [CALayer layer];
    [stroke setName:@"right_border_stoke"];
    NSArray * ar = self.layer.sublayers;
    if(ar) {
        for(int i=0; i<ar.count; i++) {
            CALayer * ca = [ar objectAtIndex:i];
            if(ca && [ca.name isEqualToString:@"right_border_stoke"]) [ca removeFromSuperlayer];
        }
    }
    stroke.frame = CGRectMake(self.frame.size.width, 0, 1, self.frame.size.height);
    stroke.backgroundColor = color.CGColor;
    [self.layer addSublayer:stroke];
    return stroke;
}
-(CALayer*) addLeftBorder:(UIColor*)color {
    CALayer * stroke = [CALayer layer];
    [stroke setName:@"left_border_stoke"];
    for(CALayer * ca in self.layer.sublayers) {
        if([ca.name isEqualToString:@"left_border_stoke"]) [ca removeFromSuperlayer];
    }
    stroke.frame = CGRectMake(0, 0, 1, self.frame.size.height);
    stroke.backgroundColor = color.CGColor;
    [self.layer addSublayer:stroke];
    return stroke;
}
-(void)setWidth:(CGFloat)width andHeight:(CGFloat)height {
    CGRect rec = self.frame;
    rec.size = CGSizeMake(width, height);
    self.frame = rec;
}
@end

//--------------------------------------------------------------
// UIImage Extensions
//--------------------------------------------------------------
@interface UIImage (UIImageExtension)
- (UIImage *)crop:(CGRect)rect;
+ (UIImage*)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;
@end
@implementation UIImage (UIImageExtension)
- (UIImage *)crop:(CGRect)rect {
    rect = CGRectMake(rect.origin.x*self.scale,
                      rect.origin.y*self.scale,
                      rect.size.width*self.scale,
                      rect.size.height*self.scale);
    
    CGImageRef imageRef = CGImageCreateWithImageInRect([self CGImage], rect);
    UIImage *result = [UIImage imageWithCGImage:imageRef
                                          scale:self.scale
                                    orientation:self.imageOrientation];
    CGImageRelease(imageRef);
    return result;
}
+ (UIImage*)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize {
    
    float hRatio = image.size.height / image.size.width;
    float vRatio = image.size.width / image.size.height;
    
    
    UIGraphicsBeginImageContext( newSize );
    [image drawInRect:CGRectMake(0, 0, newSize.width, newSize.width*hRatio)];
    UIImage * newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}
@end


//--------------------------------------------------------------
// UIColor Extensions
//--------------------------------------------------------------
@interface UIColor (Extensions)
+ (UIColor *)colorWithHex:(int)hexColor alpha:(CGFloat)alpha;
+ (UIColor *)colorWithColor:(UIColor*)color alpha:(CGFloat)alpha;
@end

@implementation UIColor (Extensions)
+ (UIColor *)colorWithHex:(int)hexColor alpha:(CGFloat)alpha {
    float r = (hexColor >> 16) & 0xff;
	float g = (hexColor >> 8) & 0xff;
	float b = (hexColor >> 0) & 0xff;
    return [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:alpha];
}
+ (UIColor *)colorWithColor:(UIColor*)color alpha:(CGFloat)alpha {
    float r,g,b,a;
    [color getRed:&r green:&g blue:&b alpha:&a];
    return [UIColor colorWithRed:r green:g blue:b alpha:alpha];
}
@end

//--------------------------------------------------------------
// NSDate Extensions
//--------------------------------------------------------------
@interface NSDate (DateExtensions)
- (NSDate*)beginningOfDay;
- (NSDate*)endOfDay;
- (NSInteger)getDay;
- (NSInteger)getMonth;
- (NSInteger)getYear;

-(NSInteger)getHour;
-(NSInteger)getMinutes;
-(NSInteger)getSeconds;


- (BOOL)isMidnight;
@end
@implementation NSDate (DateExtensions)

- (NSDate *)beginningOfDay {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
    NSDateComponents *components = [calendar components:NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit fromDate:self];
    
    return [calendar dateFromComponents:components];
}
- (NSDate *)endOfDay {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
    NSDateComponents *components = [[NSDateComponents alloc] init];
    [components setDay:1];
    
    return [[calendar dateByAddingComponents:components toDate:[self beginningOfDay] options:0] dateByAddingTimeInterval:-1];
}
-(NSInteger)getDay {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:self];
    return [components day];
}
-(NSInteger)getMonth {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:self];
    return [components month];
}
-(NSInteger)getYear {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit fromDate:self];
    return [components year];
}
-(NSInteger)getHour {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit | NSHourCalendarUnit | NSCalendarUnitSecond | NSCalendarUnitMinute fromDate:self];
    return [components hour];
    
}
-(NSInteger)getMinutes {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit | NSHourCalendarUnit | NSCalendarUnitSecond | NSCalendarUnitMinute fromDate:self];
    return [components minute];
}
-(NSInteger)getSeconds {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit | NSHourCalendarUnit | NSCalendarUnitSecond | NSCalendarUnitMinute fromDate:self];
    return [components second];
}
-(BOOL)isMidnight {
    NSDateComponents * components = [[NSCalendar currentCalendar] components:NSDayCalendarUnit | NSMonthCalendarUnit | NSYearCalendarUnit | NSHourCalendarUnit | NSCalendarUnitSecond | NSCalendarUnitMinute fromDate:self];
    return [components hour] == 0;
}
@end


//--------------------------------------------------------------
// NSDictionary Extensions
//--------------------------------------------------------------
@interface NSDictionary (NSDictionaryExtensions)
- (id)objectForKeyNotNull : (id)key;
@end
@implementation NSDictionary (NSDictionaryExtensions)
- (id)objectForKeyNotNull:(id)key {
    id object = [self objectForKey:key];
    if (object == [NSNull null]) return nil;
    return object;
}
@end
