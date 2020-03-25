#include "Service.h"

Service::Service() {
}

Service::Service(const RepositoryArray& r) {
	repo = r;
}

Service::~Service() {
}

void Service::setRepo(const RepositoryArray& r) {
	repo = r;
}

void Service::addProject(Project& p) {
	repo.addElem(p);
}

void Service::deleteProject(Project& p) {
	repo.delElem(p);
}

Project Service::updateProject(Project p, const char* g, int b, int c) {
	repo.updateElem(p, g, b, c);
	return p;
}

int Service::dimProject() {
	return repo.dim();
}

Project* Service::getAllProject() {
	return repo.getAll();
}
