#include "Service.h"

Service::Service() {
	RepositoryArray repo;
	//RepositoryArray undoArray[30];
	//int sizeUndo = -1;
}

Service::Service(const RepositoryArray& r) {
	repo = r;
}

Service::~Service() {
	//sizeUndo = 0;
}

void Service::setRepo(const RepositoryArray& r) {
	repo = r;
}

void Service::addProject(Project& p) {
	repo.addElem(p);
	//undoArray[++sizeUndo] = repo;
}

int Service::deleteProject(Project& p) {
	return repo.delElem(p);
	//undoArray[++sizeUndo] = repo;
}

Project Service::updateProject(Project p, const char* g, int b, int c) {
	repo.updateElem(p, g, b, c);
	return p;
	//undoArray[++sizeUndo] = repo;
}

int Service::dimProject() {
	return repo.dim();
}

Project* Service::getAllProject() {
	return repo.getAll();
}

int Service::getOne(Project p){
	return repo.findElem(p);
}

Project Service::projectAtPos(int i){
	return repo.elemAtPos(i);
}


//finds all the projects that have at least K branches and L commits
void Service::searchProjectService(int K, int L, Project proj[], int& m) {
	for (int i = 0; i < dimProject(); i++)
		if (getAllProject()[i].getBranches() > K&& getAllProject()[i].getCommits() > L)
			proj[m++] = getAllProject()[i];
}

//eliminarea proiectelor care au noOfBranches*totalNoOfCommits = 0
int Service::deleteProjectZero(){
	int val = 0;
	for (int i = 0; i < dimProject(); i++)
		if (getAllProject()[i].getCommits() * getAllProject()[i].getBranches() == 0)
		{
			deleteProject(getAllProject()[i]); 
			val = 1;
		}
	return val;
}

//int Service::undoLen()
//{
//	return sizeUndo;
//}

