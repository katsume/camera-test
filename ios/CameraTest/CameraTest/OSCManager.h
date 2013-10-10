//
//  OSCManager.h
//  CameraTest
//
//  Created by katsume on 2013/04/02.
//
//

#import <Foundation/Foundation.h>

@class CMAttitude;

@interface OSCManager : NSObject

- (void)sendAttitude:(CMAttitude *)attitude;

@end
