//
//  ViewController.h
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MinesweeperGame.h"

@interface ViewController : UIViewController

// A property containing the minesweeper game
@property(strong, nonatomic) MinesweeperGame* game;

@end

