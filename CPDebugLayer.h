//
//  CPDebugLayer.h
//
//  Created by Dominique d'Argent on 15.03.12.
//  Copyright 2012. All rights reserved.
//

#import "cocos2d.h"
#import "chipmunk.h"

extern NSString *const CPDebugLayerDrawShapes;
extern NSString *const CPDebugLayerDrawConstraints;
extern NSString *const CPDebugLayerDrawBBs;
extern NSString *const CPDebugLayerDrawCollisionPoints;

extern NSString *const CPDebugLayerShapeColor;
extern NSString *const CPDebugLayerConstraintColor;
extern NSString *const CPDebugLayerBBColor;
extern NSString *const CPDebugLayerCollisionPointColor;

extern NSString *const CPDebugLayerLineWidth;
extern NSString *const CPDebugLayerPointSize;

@interface CPDebugLayerColor : NSObject {

@private
    cpFloat _r, _g, _b, _a;

}

@property (nonatomic, readonly) ccColor4B ccColor4B;
@property (nonatomic, readonly) ccColor4F ccColor4F;

+ (id)colorWithR:(cpFloat)r g:(cpFloat)g b:(cpFloat)b a:(cpFloat)a;
+ (id)colorWithCCColor4B:(ccColor4B)color;
+ (id)colorWithCCColor4F:(ccColor4F)color;
+ (id)colorWithCCColor3B:(ccColor3B)color;

// designated initializer
- (id)initWithR:(cpFloat)r g:(cpFloat)g b:(cpFloat)b a:(cpFloat)a;
- (id)initWithCCColor4B:(ccColor4B)color;
- (id)initWithCCColor4F:(ccColor4F)color;
- (id)initWithCCColor3B:(ccColor3B)color;

@end

@interface CPDebugLayer : CCLayer {
    
@private
    cpSpace *_space;
    NSDictionary *_options;
    
}

@property (nonatomic, copy, setter = addOptions:) NSDictionary *options;

+ (id)debugLayerForSpace:(cpSpace *)space options:(NSDictionary *)options;
+ (NSDictionary *)defaultOptions;

- (id)initWithSpace:(cpSpace *)space options:(NSDictionary *)options;

@end
