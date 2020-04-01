//Project(gitPath, noOfBranches, totalNoOfCommits)
#include "UI.h"
#include <iostream>
#include "Tests.h"
using namespace std;

int main() {
	cout << "Start" << endl;
	runTests();
	cout << "Tests are ok!" << endl;
	Service serv;
	showUI(serv);
	return 0;
}

