//
//  RootViewController.m
//  CameraTest
//
//  Created by katsume on 2013/04/02.
//
//

#import "RootViewController.h"
#import "AttitudeManager.h"
#import "OSCManager.h"

@class CMAttitude;

@interface RootViewController ()

@property (nonatomic, retain) AttitudeManager* attitudeManager;
@property (nonatomic, retain) OSCManager* oscManager;

@end

@implementation RootViewController

#pragma mark - UIViewController methods

- (void)loadView {
	
	self.wantsFullScreenLayout= YES;

	self.view= [[[UIView alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];
	self.view.backgroundColor= [UIColor magentaColor];
	
}

- (void)viewDidLoad {
	[super viewDidLoad];
	
	self.attitudeManager= [[[AttitudeManager alloc] init] autorelease];
	
	self.attitudeManager.attitudeHandler= ^(CMAttitude* attitude){
		
		[self.oscManager sendAttitude:attitude];
	};

	self.oscManager= [[[OSCManager alloc] init] autorelease];
	
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];	
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	
	[self.attitudeManager startUpdate];
}

- (BOOL)shouldAutorotate {
	return NO;
}

- (NSUInteger)supportedInterfaceOrientations {
	return UIInterfaceOrientationMaskAll;
}

- (void)didReceiveMemoryWarning {
	
	[super didReceiveMemoryWarning];
}

- (void)viewWillDisappear:(BOOL)animated {

	[self.attitudeManager stopUpdate];

	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated {
	
	[super viewDidDisappear:animated];
}

- (void)dealloc {
	
	[_attitudeManager release];
	[_oscManager release];
	
	[super dealloc];
}

@end
