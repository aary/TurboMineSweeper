//
//  MinesweeperGame.m
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import "MinesweeperGame.h"
#define DEBUG_GAME_REVEAL


//**************************PRIVATE INTERFACE MINESWEEPERGAME**********************************
@interface MinesweeperGame()
@property (strong, nonatomic) MineMap* map;                             // The main map of mines
@property (nonatomic, getter=isGameOver, readwrite) BOOL gameOver;      // YES if the game is over
@property (nonatomic, readwrite) NSUInteger dimensions;                 // The dimensions of the map
@property (nonatomic, readwrite) NSUInteger mines;                      // The number of mines on the map
@end
//**************************PRIVATE INTERFACE MINESWEEPERGAME**********************************



@implementation MinesweeperGame

-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)minesIn {
// Default Constructor
// EFFECTS : Constructs a game with the specified dimensions and mines
    
    // Customary superclass construction
    self = [super init];
    if (self) {
        self.map = [[MineMap alloc] initWithDimensions:dimensionsIn andMines:minesIn];
        self.gameOver = NO;
        self.dimensions = dimensionsIn;
        self.mines = minesIn;
    }
    
    return self;
}

-(void) resetGame {
// MODIFIES : self
// EFFECTS : Resets the entire game with the same dimensions and mines
    self.gameOver = NO;
    self.map = [[MineMap alloc] initWithDimensions:self.dimensions andMines:self.mines];
}

-(void) resetGameWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)minesIn {
// MODIFIES : self
// EFFECTS : Resets the entire game and constructs a new minemap
    self.gameOver = NO;
    self.map = [[MineMap alloc] initWithDimensions:dimensionsIn andMines:minesIn];
    self.dimensions = dimensionsIn;
    self.mines = minesIn;
}

-(void) revealTileAtRow:(NSInteger)row andColumn:(NSInteger)column {
// REQUIRES : Requires that row and column are within the dimensions of the game or
//            else an exception is thrown
// EFFECTS : Reveals the tile at the specified row and column. If the count at the tile was 0
//           and the tile was a COUNTERTILE then a recursive search is executed that reveals all
//           neighboring COUNTERTILEs with 0 count until a COUNTERTILE with a non-zero count is hit

    // FIRST CASE
    // If the game is over then do nothing
    if (self.gameOver == YES) return;
    
    
    // INCORRECT ARGUMENTS
    if (row < 0 || column < 0 || row >= self.dimensions || column >= self.dimensions) return;
    
    
    // Reveal tile
    [self.map tileAtRow:row andColumn:column].revealed = YES;

    
    // SECOND CASE
    // If the chosen tile is a mine then the game is over and the tile is revealed
    if ([[self.map tileAtRow:row andColumn:column] tileState] == MINE) {
        self.gameOver = YES;
        
        // Reveal all mines
        NSArray* mineLocations = [self.map mineLocations];
        for (int i = 0; i < [self.map numberOfMines]; ++i) {
            [self.map tileAtRow:[[mineLocations[i] objectAtIndex:0] integerValue]
                      andColumn:[[mineLocations[i] objectAtIndex:1] integerValue]].revealed = YES;
        }
        
        // exit function
        return;
    }
    
    
    // THIRD CASE
    // If the tile has a 0 then recurse all around
    if ([[self.map tileAtRow:row andColumn:column] tileState] == COUNTERTILE &&
             [[self.map tileAtRow:row andColumn:column] count] == 0) {
        printf("Called state with args %ld and %ld\n", (long)row, (long)column);

        // 8 recursive calls for tiles all around
        if ([self.map tileAtRow:    (row - 1) andColumn:(column)].revealed != YES)
            [self revealTileAtRow:  (row - 1) andColumn:(column)];
        
        if ([self.map tileAtRow:    (row - 1) andColumn:(column + 1)].revealed != YES)
            [self revealTileAtRow:  (row - 1) andColumn:(column + 1)];
        
        if ([self.map tileAtRow:    (row) andColumn:(column + 1)].revealed != YES)
            [self revealTileAtRow:  (row) andColumn:(column + 1)];
        
        if ([self.map tileAtRow:    (row + 1) andColumn:(column + 1)].revealed != YES)
            [self revealTileAtRow:  (row + 1) andColumn:(column + 1)];
        
        if ([self.map tileAtRow:    (row + 1) andColumn:(column)].revealed != YES)
            [self revealTileAtRow:  (row + 1) andColumn:(column)];
        
        if ([self.map tileAtRow:    (row + 1) andColumn:(column - 1)].revealed != YES)
            [self revealTileAtRow:  (row + 1) andColumn:(column - 1)];
        
        if ([self.map tileAtRow:    (row) andColumn:(column - 1)].revealed != YES)
            [self revealTileAtRow:  (row) andColumn:(column - 1)];
        
        if ([self.map tileAtRow:    (row - 1) andColumn:(column - 1)].revealed != YES)
            [self revealTileAtRow:  (row - 1) andColumn:(column - 1)];
    }
    
    
#ifdef DEBUG_GAME_REVEAL
    printf("DEBUGGING MINE CHOOSING HERE\n");
    for (int i = 0; i < self.dimensions; ++i) {
        for (int j = 0; j < self.dimensions; ++j) {
            if ([self.map tileAtRow:i andColumn:j].revealed == YES) {
                printf("%d ", (int)[[self.map tileAtRow:i andColumn:j] count]);
            }
            else printf("  ");
        } printf("\n");
    }
#endif
    
    return;
    
}

-(void) toggleFlagAt:(NSInteger)row andColumn:(NSInteger)column {
// REQUIRES : Needs a valid row and column to be specified
// MODIFIES : self
// EFFECTS : toggles a flag set / not set at the location passed
    if (![self.map tileAtRow:row andColumn:column].revealed) {
        [self.map tileAtRow:row andColumn:column].flagged = ![self.map tileAtRow:row andColumn:column].flagged;
    }
}

-(Tile *) tileAtRow:(NSInteger)row andColumn:(NSInteger)column {
    return [self.map tileAtRow:row andColumn:column];
}

@end
