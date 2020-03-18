//Project(gitPath, branches, commits)
#include "Project.h"
#include <string.h>

// Constructor
Project::Project() {
	gitPath = NULL;
	branches = 0;
	commits = 0;
}

// Constructor with parameters
Project::Project(const char* gitPath, int branches, int commits) {
	this->gitPath = new char[strlen(gitPath) + 1];
	strcpy_s(this->gitPath, strlen(gitPath) + 1, gitPath);
	this->branches = branches;
	this->commits = commits;
}

// Copy constructor
Project::Project(const Project& p) {
	this->gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(this->gitPath, strlen(p.gitPath) + 1, p.gitPath);
	this->branches = p.branches;
	this->commits = p.commits;
}


// getters
char* Project::getGitPath() {
	return gitPath;
}
int Project::getBranches() {
	return branches;
}
int Project::getCommits() {
	return commits;
} 


//setters
void Project::setGitPath(const char* g) {
	if (gitPath) delete[]gitPath;
	gitPath = new char[strlen(g) + 1];
	strcpy_s(gitPath, strlen(g) + 1, g);
}
void Project::setBranches(int b) {
	branches = b;
}
void Project::setCommits(int c) {
	commits = c;
}


//Deconstructor
Project::~Project() {
	if (gitPath) delete[] gitPath;
	gitPath = NULL;
	branches = 0;
	commits = 0;
}

// assignment operator
Project& Project::operator=(const Project& p) {
	if (this == &p) return *this;
	if (gitPath) delete[] gitPath;
	gitPath = new char[strlen(p.gitPath) + 1];
	strcpy_s(gitPath, strlen(p.gitPath) + 1, p.gitPath);
	branches = p.branches;
	commits = p.commits;
	return *this;
}
//comparator
bool Project::operator==(const Project& p) {
	return (strcmp(gitPath, p.gitPath) == 0) and (branches == p.branches) and (commits == p.commits);
}