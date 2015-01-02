//
//  MineMap.h
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import <Foundation/Foundation.h>

//*********************************************************************************
@interface Tile : NSObject
// OVERVIEW : A tile class that contains the different tile states a tile can have

// The possible states of the tile
enum _TileState {COUNTERTILE, FLAG, MINE};
typedef char TileState;                                     // Typedef for memory efficiency

@property (nonatomic) TileState tileState;                  // The state of the tile, a _tileState
@property (nonatomic, getter=isRevealed) BOOL revealed;     // Whether the tile is revealed or not
@property (nonatomic) NSInteger count;                      // The number of tiles around the tile

@end
//*********************************************************************************



//*********************************************************************************
@interface MineMap : NSObject

// Default Constructor
// EFFECTS : Constructs a mine map with the passed dimensions
-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)mines;

// EFFECTS : Returns a pointer to the tile at the specified row and column
// MODIFIES : nothing, should be declared a const method
-(Tile *) tileAtRow:(NSUInteger)row andColumn:(NSUInteger)column;

@property (nonatomic) NSUInteger numberOfMines; // The number of mines in the map
@property (nonatomic) NSUInteger dimensions;    // The dimensions of the map

@end
//*********************************************************************************
