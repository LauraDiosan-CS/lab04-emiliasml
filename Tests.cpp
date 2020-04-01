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
	Project ppp("jkl", 7, 8);
	Project p0("", -1, -1);
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
	serv.addProject(pp);
	assert(serv.getAllProject()[1] == pp);
	//get one
	assert(serv.getOne(pp) == 1);
	assert(serv.getOne(ppp) == -1);
	//get elem from position i
	assert(serv.projectAtPos(1) == pp);
	assert(serv.projectAtPos(5) == p0);
}

void testServiceOperation1(){
	Service serv;
	Project p("abc", 1, 2);
	Project pp("def", 3, 4);
	Project ppp("jkl", 7, 8);
	serv.addProject(p);
	serv.addProject(pp);
	serv.addProject(ppp);
	//function that finds all the projects that have at least K branches and L commits
	Project proj[4];
	int m = 0;
	serv.searchProjectService(0, 1, proj, m);
	assert(m == 3);
	assert(proj[0] == p);
	assert(proj[1] == pp);
	assert(proj[2] == ppp);
	Project proj2[2];
	m = 0;
	serv.searchProjectService(100, 0, proj, m);
	assert(m == 0);
}

void testServiceOperation2() {
	Service serv;
	Project p("abc", 1, 2);
	Project pp("def", 3, 4);
	Project ppp("jkl", 7, 8);
	Project p4("mno", 0, 0);
	Project p5("mno", 1, 0);
	//eliminarea proiectelor care au noOfBranches*totalNoOfCommits = 0
	serv.addProject(p4);
	assert(serv.dimProject() == 1);
	assert(serv.deleteProjectZero()==1);
	assert(serv.dimProject() == 0);

	serv.addProject(p);
	serv.addProject(pp);
	serv.addProject(ppp);
	assert(serv.dimProject() == 3);
	assert(serv.deleteProjectZero()==0);
	assert(serv.dimProject() == 3);
	serv.addProject(p5);
	assert(serv.dimProject() == 4);
	assert(serv.deleteProjectZero()==1);
	assert(serv.dimProject() == 3);
}

void runTests() {
	testsProject();
	testsRepository();
	testSearchProjects();
	testSearchProjectsRepo();
	testDeleteProjZero();
	testService();
	testServiceOperation1();
	testServiceOperation2();
}