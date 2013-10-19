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

static const std::string	kAuthorTeam		= "Super Style";
static const float			kMutationRate	= 0.5f;

#pragma mark -
#pragma mark - TEAM_FUNCTIONS


static bool tArray[9];

void evaluate(int n){   //pass in tile value as n. Returns tCount as an int between 1 - 9, a measure of fiteness
    
    
    //-------- begin evaluation --------- //
    
    switch (n) {
        case 1:
            tArray[0] = true;
            break;
        case 2:
            tArray[1] = true;
            break;
        case 3:
            tArray[2] = true;
            break;
        case 4:
            tArray[3] = true;
            break;
        case 5:
            tArray[4] = true;
            break;
        case 6:
            tArray[5] = true;
            break;
        case 7:
            tArray[6] = true;
            break;
        case 8:
            tArray[7] = true;
            break;
        case 9:
            tArray[8] = true;
            break;
    }
}

bool evalMutate(int n){   //pass in tile value as n. Returns tCount as an int between 1 - 9, a measure of fiteness
    
    
    //-------- begin evaluation --------- //
    
    switch (n) {
        case 1:
            if (tArray[0] == true) {
                return true;
            }
            else {
                tArray[0] = true;
                break;
            }
        case 2:
            if (tArray[1] == true) {
                return true;
            }
            else {
                tArray[1] = true;
                break;
            }
        case 3:
            if (tArray[2] == true) {
                return true;
            }
            else {
                tArray[2] = true;
                break;
            }
        case 4:
            if (tArray[3] == true) {
                return true;
            }
            else {
                tArray[3] = true;
                break;
            }
        case 5:
            if (tArray[4] == true) {
                return true;
            }
            else {
                tArray[4] = true;
                break;
            }
        case 6:
            if (tArray[5] == true) {
                return true;
            }
            else {
                tArray[5] = true;
                break;
            }
        case 7:
            if (tArray[6] == true) {
                return true;
            }
            else {
                tArray[6] = true;
                break;
            }
        case 8:
            if (tArray[7] == true) {
                return true;
            }
            else {
                tArray[7] = true;
                break;
            }
        case 9:
            if (tArray[8] == true) {
                return true;
            }
            else {
                tArray[8] = true;
                break;
            }
    }
    return false;
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
    
    
    
    
    
    
	return (float)tCount/243;
    
}

static void crossoverFunc(const int* iBoardA, const int* iBoardB, int* oBoard, const size_t& iTileCount)
{
	//leave it at it 0-9 to limit output to 0-8, then multiply by 9. this way it will break on a 9 cell row
    //i.e., 0, 9, 18, 27, 36, 45 54, 63, or 72. this cuts down on the time some.
	int tMid = randomInt( 0, 9 );
    tMid*=9;
	for(size_t i = 0; i < iTileCount; i++) {
		if(i < tMid) { oBoard[i] = iBoardA[i]; }
		else         { oBoard[i] = iBoardB[i]; }
	}
}

static void mutateFunc(int* ioBoard, const size_t& iTileCount, const float& iMutationRate)
{
    memset(tArray, 0, 9);
    
    //--------  evaluate blocks --------- //
    for (int a = 0; a<9; a+=3) {
        for (int b = 0; b<9; b+=3) {
            
            
            for(int i = a; i < 3+a; i++) {
                for(int j = b; j < 3+b; j++) {
                    if (evalMutate(ioBoard[ i * 9 + j ]) ) {
                        ioBoard[ i * 9 + j ] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
                    }
                }
            }
            memset(tArray, 0, 9);
            
        }
    }
    
    
    //--------  evaluate rows --------- //
    
    for (int a =0; a<9; a++){
        for (int b = 0; b<9; b++){
            if (evalMutate(ioBoard[ a * 9 + b ]) ) {
                ioBoard[ a * 9 + b ] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
            }
        }
        memset(tArray, 0, 9);
    }
    
    //--------  evaluate columns --------- //
    
    for (int a =0; a<9; a++){
        for (int b = 0; b<9; b++){
            if (evalMutate(ioBoard[ b * 9 + a ]) ) {
                ioBoard[ b * 9 + a ] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
            }
        }
        memset(tArray, 0, 9);
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
