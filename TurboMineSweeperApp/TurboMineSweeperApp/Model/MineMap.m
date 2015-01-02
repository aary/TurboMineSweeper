//
//  MineMap.m
//  TurboMineSweeperApp
//
//  Created by Aaryaman Sagar on 1/2/15.
//  Copyright (c) 2015 Aaryaman Sagar. All rights reserved.
//

#import "MineMap.h"
#define DEBUG_MINEMAP

//*********************************************************************************
@implementation Tile
-(instancetype) init {_tileState = COUNTERTILE; _count = 0; return self;}
-(instancetype) initWithState:(TileState)tileStateIn {
    _tileState = tileStateIn; _count = 0; return self;
}
@end
//*********************************************************************************





//**************************PRIVATE INTERFACE MINEMAP**********************************
@interface MineMap()

// Property containing the map array
@property (strong, nonatomic) NSMutableArray* map; // Of Tiles

// REQUIRES : The specified row and column already exist in the map
// MODIFIES : self
// EFFECTS : Inserts a mine in the map at the specified location
-(void) insertMineAtRow:(NSUInteger)xCoordinate andColumn:(NSUInteger)yCoordinate;

@end
//**************************PRIVATE INTERFACE MINEMAP**********************************





//**************************IMPLEMENTATION OF MINEMAP**********************************
@implementation MineMap


-(instancetype) init {
// Defensive grounded constructor
    return nil;
}


- (NSMutableArray *) map {
// Getter for the map
    if (!_map) _map = [[NSMutableArray alloc] init];
    return _map;
}


-(instancetype) initWithDimensions:(NSUInteger)dimensionsIn andMines:(NSUInteger)mines {
// Default Constructor
// EFFECTS : Constructs a mine map with the passed dimensions
    
    // Customary superclass construction
    self = [super init];
    if (self) {
        // Set dimensions
        self.dimensions = dimensionsIn;
        
        
        // Initialize empty map with empty tiles
        self.map = [[NSMutableArray alloc] initWithCapacity:dimensionsIn];
        for (int i = 0; i < dimensionsIn; ++i) {
            // Preallcoation for effieciency
            [self.map addObject:[[NSMutableArray alloc] initWithCapacity:dimensionsIn]];
            
            for (int j = 0; j < dimensionsIn; ++j) {
                [self.map[i] addObject:[[Tile alloc] init]];
            }
        }
        

        // Populate map with mines placed in random locations
        NSUInteger xCoordinate, yCoordinate;
        for (int i = 0; i < mines; ++i) {
            // Find empty location to put a mine in the map
            do {
                xCoordinate = arc4random() % dimensionsIn;
                yCoordinate = arc4random() % dimensionsIn;
            } while ([self.map[xCoordinate][yCoordinate] tileState] == MINE);
            
            [self insertMineAtRow:xCoordinate andColumn:yCoordinate];
        }
        
#ifdef DEBUG_MINEMAP
        printf("DEBUGGING HERE\n");
        for (int i = 0; i < dimensionsIn; ++i) {
            for (int j = 0; j < dimensionsIn; ++j) {
                if (([self.map[i][j] tileState] != MINE)) printf("%d ", (int)[self.map[i][j] count]);
                else printf("X ");
            } printf("\n");
        }
#endif
        
    }
    
    return self;
}


-(Tile *) tileAtRow:(NSUInteger)row andColumn:(NSUInteger)column {
// EFFECTS : Returns a pointer to the tile at the specified row and column
    if (row >= self.dimensions || column >= self.dimensions) return nil;
    
    return self.map[row][column];
}


-(void) insertMineAtRow:(NSUInteger)xCoordinate andColumn:(NSUInteger)yCoordinate {
// REQUIRES : The specified row and column already exist in the map
// EFFECTS : Inserts a mine in the map at the specified location
    
    [self.map[xCoordinate][yCoordinate] setTileState:MINE];
    ++[self tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate - 1)].count;
    //[self   tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate - 1)].tileState  = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate)].count;
    //[self   tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate)].tileState      = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate + 1)].count;
    //[self   tileAtRow:(xCoordinate - 1) andColumn:(yCoordinate + 1)].tileState  = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate)     andColumn:(yCoordinate + 1)].count;
    //[self   tileAtRow:(xCoordinate)     andColumn:(yCoordinate + 1)].tileState  = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate + 1)].count;
    //[self   tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate + 1)].tileState  = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate)].count;
    //[self   tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate)].tileState      = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate - 1)].count;
    //[self   tileAtRow:(xCoordinate + 1) andColumn:(yCoordinate - 1)].tileState  = COUNTERTILE;
    ++[self tileAtRow:(xCoordinate)     andColumn:(yCoordinate - 1)].count;
    //[self   tileAtRow:(xCoordinate)     andColumn:(yCoordinate - 1)].tileState  = COUNTERTILE;
}

@end
