#include "UI.h"
#include <iostream>
using namespace std;

void addPr(Service& s) {
	Project proj;
	cin >> proj;
	s.addProject(proj);
	cout << " The project was added successfully!";
}

void findPr(Service& serv) {
	Project proj;
	cout << "Give the project:";
	cin >> proj;
	int rez = serv.getOne(proj);
	if (rez != -1) cout << "   Project found in position " << rez+1 << "!";
	else cout << "   The project doesn't exist!";
}

void deletePrGBC(Service& serv) {
	Project proj;
	cout << "Give the project to delete:";
	cin >> proj;
	if (serv.deleteProject(proj) == 0)
		cout << "Deleted successfully!";
	else cout << "Project not found! Delete failed";
}

void deletePrPos(Service& serv) {
	int i;
	cout << "Give the position of the project to delete:";
	cin >> i;
	i--;
	if (i >= serv.dimProject() || i < 0)
		cout << "   The position is wrong!";
	else {
		Project proj = serv.projectAtPos(i);
		if (serv.deleteProject(proj)==0)
			cout << "   Deleted successfully";
	}
}

void deletePr(Service& serv) {
	cout << "      1. Delete project by its values";
	cout << endl << "      2. Delete project by its position";
	int op;
	cout << endl << "Option:";
	cin >> op;
	if (op == 1) deletePrGBC(serv);
	else if (op == 2) deletePrPos(serv);
	else cout << "   Try again";
}


void showPrPos(Service& serv) {
	int i;
	cout << "Give the position:";
	cin >> i;
	Project p("", -1, -1);
	if (serv.projectAtPos(i-1) == p)
		cout << "   The given position is wrong!";
	else cout << "   The project in position " << i << " is: " << serv.projectAtPos(i-1);
}

void updatePr(Service& serv) {
	Project proj, p;
	int val = 1;
	cout << "Give the project";
	cin >> proj;
	while (serv.getOne(proj) == -1 && val == 1) {
		cout << "   The project doesn't exist! ";
		cout << endl << "1. Try again";
		cout << endl << "2. Exit" << endl;
		int op;
		cin >> op;
		if (op == 1) {
			cout << "Give the project";
			cin >> proj;
		}
		else val = 0;
	}
	if (val == 1) {
		cout << "Give the new parameters:";
		cin >> p;
		serv.updateProject(proj, p.getGitPath(), p.getBranches(), p.getCommits());
		cout << "    Project updated successfully";
	}
}

void showPr(Service& serv) {
	if (serv.dimProject() == 0) cout << "       There are no projects !";
	else {
		cout << endl << "---------------Projects------------------" << endl;
		for (int i = 0; i < serv.dimProject(); i++)
			cout << serv.projectAtPos(i) << endl;
		cout << "-----------------------------------------------";
	}
}

void deletePrZero(Service& serv) {
	if (serv.deleteProjectZero() == 1)
		cout << "   Projects deleted successfully";
	else cout << "   There are no projects with 0 branches or 0 commits!";
}

void showPrKL(Service& serv) {
	Project p[100];
	int m = 0, K, L;
	cout << "          Give K branches:";
	cin >> K;
	cout << "          Give L commits:";
	cin >> L;
	serv.searchProjectService(K, L, p, m);
	if (m == 0) cout << "   There are no projects with " << K << " branches and " << L << " commits!";
	else for (int i = 0; i < m; i++)
		cout << p[i] << endl;
}



void showUI(Service& serv) {
	bool val = true;
	while (val) {
		cout << endl << "---OPTIONS:" << endl;
		cout << "     1. Add project" << endl;
		cout << "     2. Search project" << endl;
		cout << "     3. Delete project" << endl;
		cout << "     4. Show project in position i" << endl;
		cout << "     5. Update project" << endl;
		cout << "     6. Show all projects" << endl;
		cout << "     7. Show all the projects that have at least K branches and L commits" << endl;
		cout << "     8. Delete all the projects that have 0 commits or/and 0 branches" << endl;
		cout << "     9. Undo" << endl;
		cout << "     0. EXIT" << endl;
		cout << "-----Choose an option:";
		int op;
		cin >> op;
		switch (op) {
		case 1: { addPr(serv); break; }
		case 2: { findPr(serv); break; }
		case 3: { deletePr(serv); break; }
		case 4: { showPrPos(serv); break; }
		case 5: {updatePr(serv); break; }
		case 6: {showPr(serv); break; }
		case 7: {showPrKL(serv); break; }
		case 8: {deletePrZero(serv); break; }
		case 9: {
			//cout << serv.undoLen();
			break; }
		case 0: {val = false; cout << "   Bye!"; break; }
		default:	cout << "   Try again!";
		}
	}
}