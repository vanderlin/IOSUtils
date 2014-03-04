//
//  FaceIcon.m
//  TimeLine
//
//  Created by Todd Vanderlin on 12/27/13.
//
//

#import "CircleImage.h"
#import "Global.h"

@implementation CircleImage


//--------------------------------------------------------------
- (id)initWithFrame:(CGRect)frame{
    
    self = [super initWithFrame:frame];
    if (self) {
        self.image = nil;
        self.backgroundColor = [UIColor redColor];
    }
    return self;
}
/*-(void)setImageForIcon:(UIImage*)iconImage {
    
    [self setImage:iconImage];
    
    
      self.contentMode = UIViewContentModeScaleAspectFit;
    
    self.layer.cornerRadius = iconImage.size.width / 2;
    self.layer.masksToBounds = YES;
    
    //[[UIImage alloc] init];
    //image = [iconImage copy];
    [self setNeedsDisplay];
}*/

//--------------------------------------------------------------
-(void)setCircleImage:(UIImage *)img {
    self.image = img;
    self.contentMode = UIViewContentModeScaleAspectFill;
    self.layer.cornerRadius = self.frame.size.width / 2;
    self.layer.masksToBounds = YES;
    
    self.layer.borderColor = [App offYellowColor].CGColor;
    self.layer.borderWidth = 1;
    
    /*
    CALayer * circle = [CALayer layer];
    
    CGFloat radius = self.frame.size.width/2;
    [circle setMasksToBounds:YES];
    [circle setBackgroundColor:[UIColor redColor].CGColor];
    [circle setCornerRadius:radius];
    [circle setBounds:CGRectMake(0, 0, radius *2.2, radius *2.2)];
    [circle setPosition:CGPointMake(radius, radius)];
    
    [self.layer addSublayer:circle];*/
}
/*
//--------------------------------------------------------------
- (void)drawRect:(CGRect)rect {
    
    CGContextRef contextRef = UIGraphicsGetCurrentContext();

    // make the mask
    if(self.image) {
        CGColorSpaceRef maskColorSpaceRef = CGColorSpaceCreateDeviceGray();
        CGContextRef mainMaskContextRef = CGBitmapContextCreate(NULL,
                                                                rect.size.width,
                                                                rect.size.height,
                                                                8,
                                                                rect.size.width,
                                                                maskColorSpaceRef,
                                                                0);
        CGColorSpaceRelease(maskColorSpaceRef);
        CGContextSetFillColorWithColor(mainMaskContextRef, [UIColor blackColor].CGColor);
        CGContextFillRect(mainMaskContextRef, rect);
        CGContextSetFillColorWithColor(mainMaskContextRef, [UIColor whiteColor].CGColor);

        CGContextMoveToPoint(mainMaskContextRef, 0, 0);
        CGContextAddEllipseInRect(mainMaskContextRef, rect);
        CGContextFillPath(mainMaskContextRef);
        
        CGImageRef mainMaskImageRef = CGBitmapContextCreateImage(mainMaskContextRef);
        CGContextRelease(mainMaskContextRef);
        CGContextSaveGState(contextRef);

        float px = 1;//rect.size.width*2 / image.size.width*2;
        float py = 1;//rect.size.height*2 / image.size.height*2;
        NSLog(@"%f %f", px, py);
        
        CGContextTranslateCTM(contextRef, 0, rect.size.height);
        CGContextScaleCTM(contextRef, px, -py);
        
        CGImageRef imageRef =  CGImageCreateWithMask(self.image.CGImage, mainMaskImageRef);

        CGContextDrawImage(contextRef, rect, imageRef);

        CGContextRestoreGState(contextRef);
        CGContextSaveGState(contextRef);
    }
}
*/

@end
