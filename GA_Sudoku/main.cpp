//////////////////////////////////////////////////
/*         Evolution as a Creative Tool         */
/*           Taught by Patrick Hebron           */
/* Interactive Telecommunications Program (ITP) */
/*             New York University              */
/*                  Fall 2013                   */
//////////////////////////////////////////////////

#include <iostream>
#include <OpenCL/OpenCL.h>

#include "Population.h"
#include "Constants.h"

#include "Solver.h"

/**
 * GENETIC SUDOKU SOLVER TOURNAMENT
 *
 * Population.h contains a basic, generalized framework for the facilitation of a genetic algorithm.
 * This file may be edited to improve performance or API accessibility but should not be edited in ways that
 * might conflict with a fair competition.
 *
 * Solver.h currently contains some functions stubs. These will be evoked by an instance of the Population class.
 * Each team should edit these functions to produce a winning Sudoku solver.
 *
 * Constants.h contains a few helper functions that are accessible through libSudokuConstants.a, a static library.
 * To help ensure a fair competition, the implementation of these methods has been masked by the use of the static library.
 */

using namespace std;


int main(int argc, const char * argv[])
{
	cout << "Running team: \'" << kAuthorTeam << "\'" << endl << endl;
	// Seed random:
	srand( (unsigned int)time( NULL ) );
	// Prepare analytics:
	size_t tAvgDuration = 0;
	size_t tAvgGenCount = 0;
	// Run each test round:
	for(int i = 0; i < getTestRunCount(); i++) {
		// Start timer:
		size_t tTimeStart = getTimeNow();
		// Create new population instance:
		Population<int>* mPopulation = new Population<int>( getPopulationSize(), getTileCount(), kMutationRate );
		// Set function bindings:
		mPopulation->setInitializeFunction( randomBoard );
		mPopulation->setFitnessFunction( fitnessFunc );
		mPopulation->setCrossoverFunction( crossoverFunc );
		mPopulation->setMutationFunction( mutateFunc );
		mPopulation->setPrintFunction( printBoard );
        
		// Initialize the population:
		mPopulation->initialize();
		// While running flag is set, keep running algorithm:
		while( mPopulation->isRunning() ) {
			mPopulation->runGeneration();
		}
		// End timer:
		size_t tTimeStop = getTimeNow();
		// Update analytics:
		tAvgDuration += ( tTimeStop - tTimeStart );
		tAvgGenCount += mPopulation->getGenerationNumber();
		// Print win state:
		mPopulation->printWinState();
		// Delete population:
		delete mPopulation;
		// Report progress:
		cout << "Test round #" << i << " completed." << endl << endl;
	}
	// Print score:
	cout << "TEAM SCORE: \'" << kAuthorTeam << "\'" << endl;
	cout << "\tAverage Duration: " << ( (float)tAvgDuration / (float)getTestRunCount() ) << " milliseconds" << endl;
	cout << "\tAverage Generation Count: " << ( (float)tAvgGenCount / (float)getTestRunCount() ) << endl;
	// Return:
    return 0;
}

