/*
  solve.cpp: contains 'main' function.

 */

#include <iostream>

#include <cstring>
#include <cstdlib>

// 221 STUDENTS: You'll need to include any .hpp files of classes that
// you create and use here
#include "PuzzleState.hpp"
#include "WolfGoatCabbage.hpp"
#include "SliderPuzzle.hpp"
#include "Sudoku.hpp"

#include "LinkedListQueue.hpp"
#include "ArrayStack.hpp"
#include "VectorPriorityQueue.hpp"
// 221 STUDENTS:  These are the ones you'll have to write.
//#include "LinkedListStack.hpp"
//#include "ArrayQueue.hpp"
//#include "HeapPriorityQueue.hpp"
#include "ComparePuzzleBadness.hpp"

#include "NullDict.hpp"
#include "LinkedListDict.hpp"
// 221 STUDENTS:  These are the ones you'll have to write.
//#include "BSTDict.hpp"
#include "ComparePuzzleState.hpp"

using namespace std;


// This function does the actual solving.
void solvePuzzle(PuzzleState *start, TodoList<PuzzleState*> &active, PredDict<PuzzleState*> &seen, vector<PuzzleState*> &solution) {

	PuzzleState *state;
	PuzzleState *temp;

	active.add(start); // Must explore the successors of the start state.
	seen.add(start,NULL); // We've seen this state.  It has not predecessor.

	cout << "In solve loop \n";
	while (!active.is_empty()) {

		// Loop Invariants:
		// 'seen' contains the set of puzzle states that we know how to reach.
		// 'active' contains the set of puzzle states that we know how to reach,
		//    and whose successors we might not have explored yet.

		state = active.remove();
		// Note:  Do not delete this, as this PuzzleState is also in 'seen'

		// The following two lines are handy for debugging, or seeing what
		// the algorithm is doing.
		cout << "Exploring State: \n";
		state->print(cout);

		if (state->isSolution()) {
			// Found a solution!
			cout << "Found solution! \n";
			//state->print(cout);

			// Follow predecessors to construct path to solution.
			temp = state;
			while (temp!=NULL) {
				cout << "Pushing back solution... \n";
				cout << "In Temp State: \n";
				temp->print(cout);

				solution.push_back(temp);
				// Guaranteed to succeed, because these states must have been
				// added to dictionary already.
				seen.find(temp,temp);
			}
			return;
		} else { cout << "State is not a solution \n"; }


		vector<PuzzleState*> nextMoves = state->getSuccessors();
		for (unsigned int i=0; i < nextMoves.size(); i++) {
			if (!seen.find(nextMoves[i], temp)) {
				// Never seen this state before.  Add it to 'seen' and 'active'
				active.add(nextMoves[i]);
				seen.add(nextMoves[i], state);
			}
		}
	}

	// Ran out of states to explore.  No solution!
	solution.clear();
	return;
}

int main (int argc, char *argv[])
{
	PuzzleState *startState;

	// 221 STUDENTS: Initialize startState with an object of the type
	// of puzzle you want solved.
	// For some kinds of puzzles, you will want to pass in a parameter
	// to specify the starting position (e.g., for the 8- or 15-puzzles.)

	startState = new WolfGoatCabbage();

	//startState = new Sudoku("000000000000000000000000000000000000000000000000000000000000000000000000000000000");

	// Note: 1/2 of all positions are not possible.  If a run takes a huge
	// amount of time, try exchanging two adjacent numbers and trying again.
	//startState = new SliderPuzzle(3,3,"8 7 6 5 4 3 2 1 0");
	//startState = new SliderPuzzle(3,4,"11 10 9 8 7 6 5 4 3 1 2 0");
	//startState = new SliderPuzzle(4,4,"15 14 13 12 11 10 9 8 7 6 5 4 3 1 2 0");


	// 221 STUDENTS:  Uncomment one of these, to select BFS, DFS, or BestFS
	// Later, you will put declarations here to use your new implementations
	// (ArrayQueue, LinkedListStack, and HeapPriorityQueue).

	// This is BFS:

	// This is BFS:
	//LinkedListQueue<PuzzleState*> activeStates;

	// This is DFS
	ArrayStack<PuzzleState*> activeStates;

	// This is BestFS
	//VectorPriorityQueue<PuzzleState*, ComparePuzzleBadness> activeStates;

	// 221 STUDENTS:  Uncomment one of these to pick the dictionary implementation
	//NullDict<PuzzleState*> seenStates;
	LinkedListDict<PuzzleState*, ComparePuzzleState> seenStates;
	//BSTDict<PuzzleState*, ComparePuzzleState> seenStates;

	vector<PuzzleState*> solution;

	solvePuzzle(startState, activeStates, seenStates, solution);

	// Print out solution
	for (int i=solution.size()-1; i >= 0; i--) {
		cout << "STEP " << solution.size()-i << ":\n";
		solution[i]->print(cout);
		cout << endl;
	}

	delete startState;

	return 0;
}
