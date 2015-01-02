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

// Default Constructor
// EFFECTS : Constructs a game with the specified dimensions and mines
-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)mines;

// REQUIRES : Requires that row and column are within the dimensions of the game or
//            else an exception is thrown
// MODIFIES : self
// EFFECTS : Reveals the tile at the specified row and column. If the count at the tile was 0
//           and the tile was a COUNTERTILE then a recursive search is executed that reveals all
//           neighboring COUNTERTILEs with 0 count until a COUNTERTILE with a non-zero count is hit
-(void) revealTileAtRow:(NSUInteger)row andColumn:(NSInteger)column;

@property (nonatomic, getter=isGameOver, readonly) BOOL gameOver;   // YES if the game is over
@property (nonatomic) NSUInteger dimensions;                        // The dimensions of the map

@end
