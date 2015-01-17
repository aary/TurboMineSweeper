//
//  ViewController.m
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import "ViewController.h"
#import "MineMap.h"
#import "MinesweeperGame.h"


@interface ViewController ()

// An outlet to the main view
@property (strong, nonatomic) IBOutlet UIView *myView;

// A 2D array of buttons in the game
@property (strong, nonatomic) NSMutableArray *mineButtons;

// If yes then touching button toggles a flag
@property(nonatomic) BOOL flagMode;

// An outlet collection for the mine buttons
//@property (strong, nonatomic) IBOutletCollection(UIButton) NSArray *mineButtons;

@end



@implementation ViewController

#define BUTTON_SIZE 30
-(void) layoutButtonsInView {
// REQUIRES : This method should only be called once for one game
// EFFECTS : Lays out all the buttons in the minesweeper game
// MODIFIES : this
    NSInteger x = 37, y = 201;
    
    // Set the buttons in the view
    for (int i = 0; i < self.game.dimensions; ++i, y += 30) {
        for (int j = 0; j < self.game.dimensions; ++j, x += 30) {
            // Place a single button
            UIButton* newButton = [UIButton buttonWithType:UIButtonTypeCustom];
            [newButton setBackgroundImage:[UIImage imageNamed:@"tile"] forState:UIControlStateNormal];
            [newButton setFrame:CGRectMake(x, y, BUTTON_SIZE, BUTTON_SIZE)];
            [self.view addSubview:newButton];
            [newButton addTarget:self action:@selector(touchMineButton:) forControlEvents:UIControlEventTouchUpInside];
            [self.mineButtons addObject:newButton];
        }
        x = 37;
    }
    
    printf("Size of array %ld\n", (unsigned long)[self.mineButtons count]);
    
    /*for (x) {
     for (y) {
     
     UIButton *newButton = [UIButton buttonWithType:UIButtonTypeInfoLight];
     [newButton setFrame:CGRectMake(x, y, 100, 100)];
     [self.myView addSubview:newButton];
     newButton
     [self.myButtons addObject:newButton];
     }
     }*/
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    // Set backgound image of view controller as a color with a pattern
    [self.view setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"background"]]];
    
    self.game = [[MinesweeperGame alloc] initWithDimensions:10 andMines:10];
    //[self.game revealTileAtRow:5 andColumn:5];
    
    // layout the buttons in the main view
    self.mineButtons = [[NSMutableArray alloc] init];
    [self layoutButtonsInView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)resetGame:(id)sender {
    self.game = [[MinesweeperGame alloc] initWithDimensions:10 andMines:10];
    [self layoutButtonsInView];
}

- (IBAction)touchMineButton:(id)sender {
// EFFECTS : Initiates the game's actions when the user touches this button
// MODIFIES : Self and other buttons in the outlet collection
    [self.game revealTileAtRow:[self.mineButtons indexOfObject:sender]/self.game.dimensions
                     andColumn:[self.mineButtons indexOfObject:sender]%self.game.dimensions];
    printf("Mine Button Touched at index %lu and %lu", [self.mineButtons indexOfObject:sender]/self.game.dimensions,
           (unsigned long)[self.mineButtons indexOfObject:sender]%self.game.dimensions);
    [self updateUI];
}

- (IBAction)toggleFlagMode:(id)sender {
// EFFECTS : Initiates the game's actions when the user touches this button
// MODIFIES : Self and other buttons in the outlet collection
    self.flagMode = !self.flagMode;
}

-(void) updateUI {
// EFFECTS : Updates the UI to reflect the current state of the game
    for (int i = 0; i < self.game.dimensions; ++i) {
        for (int j = 0; j < self.game.dimensions; ++j) {
            if ([self.game tileAtRow:i andColumn:j].revealed) {
                UIButton* temp = [self.mineButtons objectAtIndex:(i*self.game.dimensions + j)];
                NSDictionary* myDict = [NSDictionary dictionaryWithObjectsAndKeys:[UIColor blackColor], NSForegroundColorAttributeName, nil];
                if ([self.game tileAtRow:i andColumn:j].count) {
                [temp setAttributedTitle:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"%ld", (long)[self.game tileAtRow:i andColumn:j].count]
                                                                         attributes:myDict]
                                forState:UIControlStateNormal];
                }
                temp.enabled = NO;
                [temp setBackgroundImage:[UIImage imageNamed:@"touchdowntile"] forState:UIControlStateNormal];
            }
        }
    }
}


@end
