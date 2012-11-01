#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>

#define NUMWALLS	32

typedef enum {
	BLOCK_VERTICAL,
	BLOCK_HORIZONTAL
} levelBlockType;

typedef enum {
	NETWORK_ACK,					// no packet
	NETWORK_COINTOSS,				// decide who is going to be the server
	NETWORK_MOVE_EVENT,				// send position
	NETWORK_FIRE_EVENT,				// send fire
	NETWORK_HEARTBEAT				// send of entire state at regular intervals
} packetCodes;

typedef struct {
	CGPoint		tankPreviousPosition;
	CGPoint		tankPosition;
	CGPoint		tankMissilePosition;
	CGPoint		tankDestination;
	
	float		tankRotation;
	float		tankDirection;
	float		tankMissileDirection;
	int			tankMissile;
} tankInfo;

@interface TankViewController : UIViewController <GKPeerPickerControllerDelegate, GKSessionDelegate, UIAlertViewDelegate> {
	IBOutlet	UIImageView		*tank1;
	IBOutlet	UIImageView		*tank2;
	IBOutlet	UIImageView		*missile1;
	IBOutlet	UIImageView		*missile2;
	
	IBOutlet	UILabel			*gameLabel;
	IBOutlet	UILabel			*score1;
	IBOutlet	UILabel			*score2;
    
	UIImageView	*walls[NUMWALLS];
	
	UIImage		*levelBlockV;
	UIImage		*levelBlockH;
	
	CGPoint		tank1Start;
	CGPoint		tank2Start;
	tankInfo	tankStats[2];
	
	int			levelBlocks;
	int			playerScore1, playerScore2;
	
	NSInteger	gameState;
	NSInteger	peerStatus;
	
	// networking
	GKSession		*gameSession;
	int				gameUniqueID;
	int				gamePacketNumber;
	NSString		*gamePeerId;
	NSDate			*lastHeartbeatDate;
	
	UIAlertView		*connectionAlert;
}

@property(nonatomic, retain) IBOutlet UIImageView	*tank1;
@property(nonatomic, retain) IBOutlet UIImageView	*tank2;
@property(nonatomic, retain) IBOutlet UIImageView	*missile1;
@property(nonatomic, retain) IBOutlet UIImageView	*missile2;
@property(nonatomic, retain) IBOutlet UILabel		*gameLabel;
@property(nonatomic, retain) IBOutlet UILabel		*score1;
@property(nonatomic, retain) IBOutlet UILabel		*score2;
@property(nonatomic, retain) UIImage *levelBlockV;
@property(nonatomic, retain) UIImage *levelBlockH;

@property(nonatomic) NSInteger		gameState;
@property(nonatomic) NSInteger		peerStatus;

@property(nonatomic, retain) GKSession	 *gameSession;
@property(nonatomic, copy)	 NSString	 *gamePeerId;
@property(nonatomic, retain) NSDate		 *lastHeartbeatDate;
@property(nonatomic, retain) UIAlertView *connectionAlert;

- (void)invalidateSession:(GKSession *)session;

- (void)playerReset;
- (void)updateTanks;
- (void)gameLoop;
- (void)addToLevel:(levelBlockType)bType atX:(float)x atY:(float)y width:(float)w height:(float)h;
- (void)sendNetworkPacket:(GKSession *)session packetID:(int)packetID withData:(void *)data ofLength:(int)length reliable:(BOOL)howtosend;
- (BOOL)parseXMLFileAtURL:(NSURL *)URL parseError:(NSError **)error;

@end
