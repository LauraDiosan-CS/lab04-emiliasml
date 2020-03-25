#include "assert.h"
#include "Tests.h"
#include "Repository.h"
#include  "Project.h"
#include "Operations.h"
#include "Service.h"
#include <string.h>

void testsProject() {
	Project p;
	assert(p.getGitPath() == NULL);
	assert(p.getBranches() == 0);
	assert(p.getCommits() == 0);
	//---------------------------------------------
	Project p1("nr1", 10, 100);
	//getters
	assert(strcmp(p1.getGitPath(), "nr1") == 0);
	assert(p1.getBranches() == 10);
	assert(p1.getCommits() == 100);
	//setters
	p1.setGitPath("da");
	assert(strcmp(p1.getGitPath(), "da") == 0);
	p1.setBranches(9);
	assert(p1.getBranches() == 9);
	p1.setCommits(900);
	assert(p1.getCommits() == 900);
	//-------------------------------------------
	Project pp;
	pp = p1;
	assert(p1 == pp);
	assert(p1.getBranches() == pp.getBranches());
}

void testsRepository() {
	Project p1("nr1", 10, 100);
	Project p2("nr2", 20, 200);
	Project p3("nr3", 30, 300);
	Project p4("nr0", 0, 9000);

	RepositoryArray rep;
	//size and add
	assert(rep.dim() == 0);
	rep.addElem(p1);
	rep.addElem(p2);
	rep.addElem(p3);
	rep.addElem(p4);
	assert(rep.dim() == 4);
	//delete
	rep.delElem(p4);
	assert(rep.dim() == 3);
	rep.delElem(p3);
	assert(rep.dim() == 2);
	//getAll
	assert(rep.getAll()[0] == p1);
	assert(rep.getAll()[1] == p2);
	//update
	assert(strcmp(rep.getAll()[0].getGitPath(), "nr1") == 0);
	rep.updateElem(rep.getAll()[0], "abc", 1, 2);
	assert(strcmp(rep.getAll()[0].getGitPath(), "abc") == 0);
	assert(strcmp(p1.getGitPath(), "nr1") == 0);
	//get item from position
	assert(rep.getItemFromPos(1) == p2);
	//find element
	assert(rep.findElem(p2) == 1);
}

void testSearchProjects() {
	Project p1("nr1", 10, 100);
	Project p2("nr2", 20, 200);
	Project p3("nr3", 30, 300);
	Project p4("nr0", 0, 9000);
	Project pr[4] = { p1, p2, p3, p4 };
	Project rez[4];
	int m = -1;
	searchProjects(pr, 4, 9, 101, rez, m);
	assert(m == 1);
	assert(rez[0] == p2);
	assert(rez[1] == p3);
}

void testSearchProjectsRepo() {
	Project p1("nr1", 10, 100);
	Project p2("nr2", 20, 200);
	Project p3("nr3", 30, 300);
	Project p4("nr0", 0, 9000);
	RepositoryArray rep;
	rep.addElem(p1);
	rep.addElem(p2);
	rep.addElem(p3);
	rep.addElem(p4);
	Project rez[4];
	int m = 0;
	searchProjectsRepo(rep, 9, 101, rez, m);
	assert(m == 2);
	assert(rez[0] == p2);
	assert(rez[1] == p3);
}

void testDeleteProjZero() {
	Project p1("nr1", 0, 100);
	Project p2("nr2", 0, 200);
	Project p3("nr3", 0, 300);
	Project p4("nr0", 10, 9000);
	RepositoryArray rep;
	rep.addElem(p1);
	assert(rep.dim() == 1);
	deleteProjZero(rep);
	assert(rep.dim() == 0);
	rep.addElem(p2);
	rep.addElem(p3);
	rep.addElem(p4);
	assert(rep.dim() == 3);
	deleteProjZero(rep);
	assert(rep.dim() == 1);
}

void testService() {
	Service serv;
	Project p("abc", 1, 2);
	Project pp("def", 3, 4);
	//add and size 
	assert(serv.dimProject() == 0);
	serv.addProject(p);
	assert(serv.dimProject() == 1);
	serv.addProject(pp);
	assert(serv.dimProject() == 2);
	//delete
	serv.deleteProject(pp);
	assert(serv.dimProject() == 1);
	//update and getAll
	serv.updateProject(serv.getAllProject()[0], "ghi", 5, 6);
	assert(serv.getAllProject()[0].getBranches() == 5);
	assert(strcmp(serv.getAllProject()[0].getGitPath(), "ghi") == 0);
	assert(serv.getAllProject()[0].getCommits() == 6);
}

void runTests() {
	testsProject();
	testsRepository();
	testSearchProjects();
	testSearchProjectsRepo();
	testDeleteProjZero();
	testService();
}