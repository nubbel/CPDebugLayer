**CPDebugLayer** is a CCLayer subclass that helps visualize and debug your physics by drawing shape outlines and bounding boxes, constraints (joints) and collision points. It is based on 'drawSpace.c' by Scott Lembcke but targets Cocos2d 2.0 and OpenGL ES 2.0. As opposed to other Chipmunk debug helper CPDebugLayer is designed to use as little private API as possible (currently only 3 uses) - 'chipmunk_private.h' is not even required - which makes it a lot more stable. Cocos2d's 'CCDrawingPrimitives' are used for drawing in OpenGL ES 2.0.

##Features##

CPDebugLayer can be configured to draw the following Chipmunk debug information:

- shape outlines
- shape bounding boxes
- constraints (joints)
- collision points

###Supported shapes###

All kind of shapes are supported: circle, segment and poly shapes!

###Supported constraint/joint types:###

- pin, slide, pivot and groove joint
- damped springs is in the work and will be added shortly

##Usage##
Using the CPDebugLayer is as simple as that:

    // create chipmunk debug layer
    CCLayer *debugLayer = [[CPDebugLayer alloc] initWithSpace:_space options:nil];
    [self addChild:debugLayer z:0]; // higher z than your other layers

It can be configured by passing a `NSDictionary` for the options parameter.

##Configuration options##

| Option                          | Description                              | Default value |
|---------------------------------|------------------------------------------|---------------|
| CPDebugLayerDrawShapes          | Enables drawing of shape outlines.       | YES           |
| CPDebugLayerDrawConstraints     | Enables drawing of constraints/joints.   | YES           |
| CPDebugLayerDrawBBs             | Enables drawing of shape bounding boxes. | NO            |
| CPDebugLayerDrawCollisionPoints | Enables drawing of collision points.     | YES           |
| CPDebugLayerShapeColor          | Sets the color for shape outlines.       | green         |
| CPDebugLayerConstraintColor     | Sets the color for constraints/joints.   | blue          | 
| CPDebugLayerBBColor             | Sets the color for shape bounding boxes. | yellow        | 
| CPDebugLayerCollisionPointColor | Sets the color for collision points.     | magenta       | 
| CPDebugLayerLineWidth           | Sets the line width for drawing.         | 2.0           | 
| CPDebugLayerPointSize           | Sets the point size for drawing.         | 5.0           | 

###Example###
The following dictionary represents the default options:

    [NSDictionary dictionaryWithObjectsAndKeys:
     [NSNumber numberWithBool:YES], CPDebugLayerDrawShapes,
     [NSNumber numberWithBool:YES], CPDebugLayerDrawConstraints,
     [NSNumber numberWithBool:NO], CPDebugLayerDrawBBs,
     [NSNumber numberWithBool:YES], CPDebugLayerDrawCollisionPoints,
     [CPDebugLayerColor colorWithCCColor3B:ccGREEN], CPDebugLayerShapeColor,
     [CPDebugLayerColor colorWithCCColor3B:ccBLUE], CPDebugLayerConstraintColor,
     [CPDebugLayerColor colorWithCCColor3B:ccYELLOW], CPDebugLayerBBColor,
     [CPDebugLayerColor colorWithCCColor3B:ccMAGENTA], CPDebugLayerCollisionPointColor,
     [NSNumber numberWithFloat:2.0f], CPDebugLayerLineWidth,
     [NSNumber numberWithFloat:5.0f], CPDebugLayerPointSize,
     nil];

###Color values###

Color values are represented by the `CPDebugLayerColor` class as seen in the example above. A color object can be created by passing red, green, blue and alpha values, by passing a ccColor4F, a ccColor4B or a ccColor3B.


    // create a red color
    CPDebugLayerColor *red;
    
    // using r,g, b, a values
    red = [CPDebugLayerColor colorWithR:1.0f g:0.0f b:0.0f a:1.0f];
    
    // using ccColor4F
    red = [CPDebugLayerColor colorWithCCColor4F:(ccColor4F) {1.0f, 0.0f, 0.0f, 1.0f}];
    
    // using ccColor4B
    red = [CPDebugLayerColor colorWithCCColor4B:ccc4(255, 0, 0, 255)];
    
    // using ccColor3B
    red = [CPDebugLayerColor colorWithCCColor3B:ccc3(255, 0, 0)];
    
    // using color constants
    red = [CPDebugLayerColor colorWithCCColor3B:ccRED];

##Planned improvements##

I've noticed accessing a `NSDictionary` multiple times per frame drops the frame rate. In future I'll use a C struct holding the config data internally, but still offer the nice Objective-C API using a dictionary.