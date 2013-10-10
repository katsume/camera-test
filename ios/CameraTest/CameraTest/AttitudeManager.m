//
//  AttitudeManager.m
//  CameraTest
//
//  Created by katsume on 2013/04/02.
//
//

#import "AttitudeManager.h"
#import <CoreMotion/CoreMotion.h>

@interface AttitudeManager()

@property (nonatomic, readonly) CMMotionManager* motionManager;

@end

@implementation AttitudeManager

- (void)startUpdate {
	
	if(!self.motionManager.isDeviceMotionAvailable ||
	   !([CMMotionManager availableAttitudeReferenceFrames] & CMAttitudeReferenceFrameXTrueNorthZVertical)){
		return;
	}
	
	NSOperationQueue* queue= [[[NSOperationQueue alloc] init] autorelease];
	[self.motionManager startDeviceMotionUpdatesUsingReferenceFrame:CMAttitudeReferenceFrameXTrueNorthZVertical
															toQueue:queue
														withHandler:^(CMDeviceMotion* motion, NSError* error){
															self.attitudeHandler(motion.attitude);
														}];
	
}

- (void)stopUpdate {
	
	[self.motionManager stopDeviceMotionUpdates];
}

#pragma mark - NSObject methods

- (id)init {
	
	self = [super init];
	if (self) {
		
		
		_motionManager= [[CMMotionManager alloc] init];
		_motionManager.deviceMotionUpdateInterval= 1.0/30.0;
		
	}
	return self;
}

- (void)dealloc {
	
	[_attitudeHandler release];
	
	[_motionManager release];
	
	[super dealloc];
}

@end