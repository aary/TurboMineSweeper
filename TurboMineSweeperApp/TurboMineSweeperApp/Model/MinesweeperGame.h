//
//  MinesweeperGame.h
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MineMap.h"

@interface MinesweeperGame : NSObject
// OVERVIEW : The game class for a game of Minesweeper


// Default Constructor
// EFFECTS : Constructs a game with the specified dimensions and mines
-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)mines;

// MODIFIES : self
// EFFECTS : Resets the entire game with the same dimensions and mines
-(void) resetGame;

// MODIFIES : self
// EFFECTS : Resets the entire game and constructs a new minemap
-(void) resetGameWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)minesIn;

// REQUIRES : Requires that row and column are within the dimensions of the game or
//            else an exception is thrown
// MODIFIES : self
// EFFECTS : Reveals the tile at the specified row and column. If the count at the tile was 0
//           and the tile was a COUNTERTILE then a recursive search is executed that reveals all
//           neighboring COUNTERTILEs with 0 count until a COUNTERTILE with a non-zero count is hit
-(void) revealTileAtRow:(NSInteger)row andColumn:(NSInteger)column;

// REQUIRES : Needs a valid row and column to be passed in, both < dimensions
// MODIFIES : nothing, should have been declared a const function
// EFFECTS : Returns the tile linked to the map in the game
-(Tile *) tileAtRow:(NSInteger)row andColumn:(NSInteger)column;

// REQUIRES : Needs a valid row and column to be specified
// MODIFIES : self
// EFFECTS : toggles a flag set / not set at the location passed
-(void) toggleFlagAt:(NSInteger)row andColumn:(NSInteger)column;

@property (nonatomic, getter=isGameOver, readonly) BOOL gameOver;   // YES if the game is over
@property (nonatomic, readonly) NSUInteger dimensions;              // The dimensions of the map
@property (nonatomic, readonly) NSUInteger mines;                   // The number of mines on the map

@end
