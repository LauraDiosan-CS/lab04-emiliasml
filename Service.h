#pragma once
#include "Repository.h"
#include "Project.h"

class Service {
private:
	RepositoryArray repo;
public:
	Service();
	Service(const RepositoryArray&);
	void setRepo(const RepositoryArray&);
	void addProject(Project&);
	void deleteProject(Project&);
	Project updateProject(Project, const char*, int, int);
	int dimProject();
	Project* getAllProject();
	~Service();
};