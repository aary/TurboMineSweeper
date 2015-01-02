//
//  MinesweeperGame.m
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import "MinesweeperGame.h"



//**************************PRIVATE INTERFACE MINESWEEPERGAME**********************************
@interface MinesweeperGame()
@property (strong, nonatomic) MineMap* map;                             // The main map of mines
@property (nonatomic, getter=isGameOver, readwrite) BOOL gameOver;      // YES if the game is over
@end
//**************************PRIVATE INTERFACE MINESWEEPERGAME**********************************



@implementation MinesweeperGame

-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)mines {
// Default Constructor
// EFFECTS : Constructs a game with the specified dimensions and mines
    
    // Customary superclass construction
    self = [super init];
    if (self) {
        self.map = [[MineMap alloc] initWithDimensions:dimensionsIn andMines:mines];
        self.gameOver = NO;
        self.dimensions = dimensionsIn;
    }
    
    return self;
}

-(void) revealTileAtRow:(NSUInteger)row andColumn:(NSInteger)column {
// REQUIRES : Requires that row and column are within the dimensions of the game or
//            else an exception is thrown
// EFFECTS : Reveals the tile at the specified row and column. If the count at the tile was 0
//           and the tile was a COUNTERTILE then a recursive search is executed that reveals all
//           neighboring COUNTERTILEs with 0 count until a COUNTERTILE with a non-zero count is hit
}

@end
