#pragma once
#include <iostream>
#include <string>
using namespace std;
//Project(gitPath, noOfBranches, totalNoOfCommits)
class Project {
private:
	char* gitPath;
	int branches;
	int commits;
public:
	Project();
	Project(const char*, int, int);
	Project(const Project&);
	Project& operator=(const Project&);
	char* getGitPath();
	int getBranches();
	int getCommits();
	void setGitPath(const char*);
	void setBranches(int);
	void setCommits(int);
	bool operator==(const Project&);
	Project(string);
	friend ostream& operator<<(ostream& os, Project p);
	friend istream& operator>>(istream&, Project&);
	~Project();

};