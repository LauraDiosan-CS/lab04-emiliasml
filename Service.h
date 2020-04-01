#pragma once
#include "Repository.h"
#include "Project.h"

class Service {
private:
	RepositoryArray repo;
	//RepositoryArray undoArray[30];
	//int sizeUndo;
public:
	Service();
	Service(const RepositoryArray&);
	void setRepo(const RepositoryArray&);
	void addProject(Project&);
	int deleteProject(Project&);
	Project updateProject(Project, const char*, int, int);
	int dimProject();
	Project* getAllProject();
	int getOne(Project);
	Project projectAtPos(int);
	void searchProjectService(int, int, Project[], int &);
	int deleteProjectZero();
	//int undoLen();
	~Service();
};