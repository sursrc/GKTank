#import <UIKit/UIKit.h>

@class TankViewController;

@interface TankAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    TankViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet TankViewController *viewController;

@end

