#include <iostream>
#include "assert.h"
#include "Tests.h"
#include "Repository.h"
#include  "Project.h"
#include <string.h>
using namespace std;

void testsProject() {
	Project p;
	assert(p.getGitPath() == NULL);
	assert(p.getBranches() == 0);
	assert(p.getCommits() == 0);
	//---------------------------------------------
	Project p1("nr1", 10, 100);
	Project p2("nr2", 20, 200);
	Project p3("nr3", 30, 300);
	Project p4("nr0", 0, 9000);

	assert(strcmp(p1.getGitPath(), "nr1") == 0);
	assert(strcmp(p2.getGitPath(), "nr2") == 0);
	assert(strcmp(p3.getGitPath(), "nr3") == 0);
	assert(strcmp(p4.getGitPath(), "nr0") == 0);

	assert(p1.getBranches() == 10);
	assert(p2.getBranches() == 20);

	assert(p3.getCommits() == 300);
	assert(p4.getCommits() == 9000);

	p1.setBranches(1);
	assert(p1.getBranches() == 1);
	p4.setCommits(9);
	assert(p4.getCommits() == 9);
	p1.setGitPath("da");
	assert(strcmp(p1.getGitPath(), "da") == 0);
	//-------------------------------------------
	Project pp;
	pp = p1;
	assert(p1 == pp);
	assert(p1.getBranches() == pp.getBranches());
}

//============================================================\\

void testsRepository(){
	Project p1("nr1", 10, 100);
	Project p2("nr2", 20, 200);
	Project p3("nr3", 30, 300);
	Project p4("nr0", 0, 9000);

	RepositoryArray rep;

	assert(rep.dim() == 0);
	rep.addElem(p1);
	rep.addElem(p2);
	rep.addElem(p3);
	rep.addElem(p4);
	assert(rep.dim() == 4);

	rep.delElem(p4);
	assert(rep.dim() == 3);
	rep.delElem(p3);
	assert(rep.dim() == 2);

	assert(rep.getAll()[0] == p1);
	assert(rep.getAll()[1] == p2);
}