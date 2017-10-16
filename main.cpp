/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 * Now also doing testing & height calculations
 *
 * Aaron Crandall - 2016 - Added / updated: Ngoc Duong
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *  * Also doing height calculations
 *
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <fstream> //input file, output file
#include <math.h> //log
#include "BST.h"
#include "TestData.h"
using namespace std;

/*
 *  Interface to run all tests if --test is passed on command line
 */
void runTests() {
	cout << " [x] Running tests. " << endl;
	TestData *testing = new TestData();			// Create object with testing data and interfaces

  BST<int> *bst_test = new BST<int>;

	/* Should make a tree like this:
              10
         5          14
     1      7           17
                            19
                          18

   */
	int testval = testing->get_next_minitest();
	while( testval >= 0 ){
		bst_test->add( testval );
		testval = testing->get_next_minitest();
	}
	cout << " [x] Should print out in pre order: 10 5 1 7 14 17 19 18 " << endl;
  cout << " [x] Resulting print out test:      ";
	bst_test->printPreOrder();
  cout << endl;

	cout << " [x] Should print a tree height of  : 5" << endl;
  cout << " [x] Currently calculating height of: ";
  cout << bst_test->height();
  cout << endl;
}

/*
 * Generate the CSV file for the project output here
 */
void genCSV() {
	cout << " [x] Generating CSV output file. " << endl;

    TestData *testing = new TestData();

    //Report to CSV file
    ofstream outfile("OutputData-BST.csv");
    outfile << "N,log_2(N),Sorted,Balanced,Scrambled #0,Scrambled #1,\
Scrambled #2,Scrambled #3,Scrambled #4" << endl;

	// make 7 trees (sorted, balanced, scrambled[0..4])
    BST <int>*bst_sorted = new BST<int>();
    BST <int>*bst_balanced = new BST<int>();
    BST <int>*bst_scrambled_0 = new BST<int>();
    BST <int>*bst_scrambled_1 = new BST<int>();
    BST <int>*bst_scrambled_2 = new BST<int>();
    BST <int>*bst_scrambled_3 = new BST<int>();
    BST <int>*bst_scrambled_4 = new BST<int>();

    //initiate first data for each tree
    int sorted = testing->get_next_sorted();
    int balanced = testing->get_next_balanced();
    int scrambled_0 = testing->get_next_scrambled(0);
    int scrambled_1 = testing->get_next_scrambled(1);
    int scrambled_2 = testing->get_next_scrambled(2);
    int scrambled_3 = testing->get_next_scrambled(3);
    int scrambled_4 = testing->get_next_scrambled(4);


	// output to outfile while fill each tree with data from TestData
    while(sorted >= 0 || balanced >= 0 || scrambled_0 >= 0 ||
scrambled_1 >= 0 || scrambled_2 >= 0 || scrambled_3 >= 0 || scrambled_4 >= 0)
    {
        //add one data to each tree
		bst_sorted->add( sorted );
        bst_balanced->add( balanced );
        bst_scrambled_0->add( scrambled_0 );
        bst_scrambled_1->add( scrambled_1 );
        bst_scrambled_2->add( scrambled_2 );
        bst_scrambled_3->add( scrambled_3 );
        bst_scrambled_4->add( scrambled_4 );

        //output to outfile
        outfile << bst_sorted->nodesCount() << "," <<
log(bst_sorted->nodesCount())/log(2) << "," <<
bst_sorted->height() << "," <<
bst_balanced->height() << "," <<
bst_scrambled_0->height() << "," <<
bst_scrambled_1->height() << "," <<
bst_scrambled_2->height() << "," <<
bst_scrambled_3->height() << "," <<
bst_scrambled_4->height() << endl;

        //update statements
		sorted = testing->get_next_sorted();
        balanced = testing->get_next_balanced();
        scrambled_0 = testing->get_next_scrambled(0);
        scrambled_1 = testing->get_next_scrambled(1);
        scrambled_2 = testing->get_next_scrambled(2);
        scrambled_3 = testing->get_next_scrambled(3);
        scrambled_4 = testing->get_next_scrambled(4);
	}
    outfile.close();
}

/*
 *   Main function for execution
 */
int main( int argc, char* argv[] ) {
	if( argc > 1 && !strcmp(argv[1], "--test") )
	{
		cout << " [x] Program in test mode, doing simple tests. " << endl;
		runTests();  // testing should just do a simple tree insert set and search
	}
	else
	{
		cout << " [x] Program built and running in full CSV generation mode. " << endl;
		genCSV();
	}
	return 0;
}
