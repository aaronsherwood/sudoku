//////////////////////////////////////////////////
/*         Evolution as a Creative Tool         */
/*           Taught by Patrick Hebron           */
/* Interactive Telecommunications Program (ITP) */
/*             New York University              */
/*                  Fall 2013                   */
//////////////////////////////////////////////////

#pragma once

#include "Constants.h"
#include <array>

/**
 * THE CONTENTS OF THIS FILE SHOULD BE EDITED TO PRODUCE A WINNING SUDOKU SOLVER...
 */

#pragma mark -
#pragma mark - TEAM_PARAMS

static const std::string	kAuthorTeam		= "Aaron Test App";
static const float			kMutationRate	= 0.5f;

#pragma mark -
#pragma mark - TEAM_FUNCTIONS


static bool tArray[9];

void evaluate(int n){   //pass in tile value as n. Returns tCount as an int between 1 - 9, a measure of fiteness
    
    
    //-------- begin evaluation --------- //

        switch (n) {
            case 1: tArray[0] = true;
            case 2: tArray[1] = true;
            case 3: tArray[2] = true;
            case 4: tArray[3] = true;
            case 5: tArray[4] = true;
            case 6: tArray[5] = true;
            case 7: tArray[6] = true;
            case 8: tArray[7] = true;
            case 9: tArray[8] = true;
        }
    

    //std::cout << "tCount: " << tCount << std::endl;
    //return tCount;
}



static float fitnessFunc(const int* iBoard, const size_t& iTileCount)
{

    memset(tArray, 0, 9);
    int tCount = 0;
    //--------  evaluate blocks --------- //
    
    for (int a = 0; a<9; a+=3) {
        for (int b = 0; b<9; b+=3) {
            
            for(int i = a; i < 3+a; i++) {
                for(int j = b; j < 3+b; j++) {
                    evaluate(iBoard[ i * 9 + j ] );
                }
            }
            for(int i=0; i<9; i++){
                if(tArray[i] == true) tCount++;
            }
            memset(tArray, 0, 9);

        }
    }
    
    
    //--------  evaluate rows --------- //
    
    for (int a =0; a<9; a++){
        for (int b = 0; b<9; b++){
            evaluate(iBoard[ a * 9 + b ] );
        }
        for(int i=0; i<9; i++){
            if(tArray[i] == true) tCount++;
        }
        memset(tArray, 0, 9);
    }
    
     //--------  evaluate columns --------- //
    
    for (int a =0; a<9; a++){
        for (int b = 0; b<9; b++){
            evaluate(iBoard[ b * 9 + a ] );
        }
        for(int i=0; i<9; i++){
            if(tArray[i] == true) tCount++;
        }
        memset(tArray, 0, 9);
    }

    //std::cout << "tCount: " << tCount << std::endl;
    
    
    int one, two, three, four, five, six, seven, eight, nine;
    
    for (int i=0; i<81; i++){
        if(iBoard[i] == 1) one++;
        if(iBoard[i] == 1) two++;
        if(iBoard[i] == 1) three++;
        if(iBoard[i] == 1) four++;
        



        
        }
    
    
    
    
    
	return (float)tCount/729;
    
}

static void crossoverFunc(const int* iBoardA, const int* iBoardB, int* oBoard, const size_t& iTileCount)
{
	// EXERCISE: Please feel free to replace the contents of this function to improve upon your algorithm's performance...
	
	int tMid = randomInt( 0, (int)iTileCount );
	for(size_t i = 0; i < iTileCount; i++) {
		if(i < tMid) { oBoard[i] = iBoardA[i]; }
		else         { oBoard[i] = iBoardB[i]; }
	}
}

static void mutateFunc(int* ioBoard, const size_t& iTileCount, const float& iMutationRate)
{
	// EXERCISE: Please feel free to replace the contents of this function to improve upon your algorithm's performance...
	
	for(int i = 0; i < iTileCount; i++) {
		if( ( (float)rand() / (float)RAND_MAX ) < iMutationRate ) {
			ioBoard[i] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
		}
	}
}

static void randomBoard(int* ioBoard, const size_t& iTileCount)
{
	// EXERCISE: The contents of this function can be edited for testing, but will be reverted for league play...
	
	for(int i = 0; i < iTileCount; i++) {
		ioBoard[i] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
	}
}

static void printBoard(int* iBoard, const size_t& iTileCount)
{
	// EXERCISE: The contents of this function can be edited for testing, but will be reverted for league play...
	
	int tAxisLen = sqrt( iTileCount );
	printf( "%ix%i BOARD:\n", tAxisLen, tAxisLen );
	for(int i = 0; i < tAxisLen; i++) {
		for(int j = 0; j < tAxisLen; j++) {
			printf( "%i ", iBoard[ i * tAxisLen + j ] );
		}
		printf( "\n" );
	}
	printf( "\n" );
    
}