//
//  AttitudeManager.h
//  CameraTest
//
//  Created by katsume on 2013/04/02.
//
//

#import <Foundation/Foundation.h>

@class CMAttitude;

@interface AttitudeManager : NSObject

@property (nonatomic, copy) void (^attitudeHandler)(CMAttitude*);

- (void)startUpdate;
- (void)stopUpdate;

@end
