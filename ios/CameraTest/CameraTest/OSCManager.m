//
//  OSCManager.m
//  CameraTest
//
//  Created by katsume on 2013/04/02.
//
//

#import "OSCManager.h"
#import "OSCPort.h"

#import <CoreMotion/CoreMotion.h>

static char* const kTargetIPAddress= "192.168.21.187";
static short const kTargetPort= 12345;

@interface OSCManager()

@property (nonatomic, readonly) OSCPort* oscPort;

@end

@implementation OSCManager

- (void)sendAttitude:(CMAttitude *)attitude {
	
	CMQuaternion quaternion= attitude.quaternion;
	
	[self.oscPort sendTo:"/attitude" types:"ffff", (float)quaternion.x, (float)quaternion.y, (float)quaternion.z, (float)quaternion.w];
}

#pragma mark - NSObject methods

- (id)init {
	
	self = [super init];
	if (self) {
		
		_oscPort= [[OSCPort oscPortToAddress:kTargetIPAddress portNumber:kTargetPort] retain];
	}
	return self;
}

- (void)dealloc {
	
	[_oscPort release];
	
	[super dealloc];
}

@end
