#pragma once
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
	~Project();

};