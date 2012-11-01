#import "TankAppDelegate.h"
#import "TankViewController.h"

@implementation TankAppDelegate

@synthesize window;
@synthesize viewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {
    
	application.idleTimerDisabled = YES; // we don't want the screen to sleep during our game
	
    // Override point for customization after app launch
    [self.window addSubview:viewController.view];
    [self.window makeKeyAndVisible];
}


- (void)dealloc {
    [self.viewController release];
    [self.window release];
    [super dealloc];
}


@end
