#include "Operations.h"
#include "Repository.h"
#include "Project.h"
//finds all the projects that have at least K branches and L commits
//In: a list of projects, its length, the value K for branches, the value L for commits, an array for found projects and its length
//Out: an array with all the projects with the wanted property
void searchProjects(Project proj[], int n, int K, int L, Project projFound[], int& m) {
	for (int i = 0; i < n; i++)
		if (proj[i].getBranches() > K&& proj[i].getCommits() > L) {
			m++;
			projFound[m] = proj[i];
		}
}

void searchProjectsRepo(RepositoryArray& rep, int K, int L, Project projFound[], int& m) {
	m = 0;
	for (int i = 0; i < rep.dim(); i++) {
		if (rep.getItemFromPos(i).getBranches() > K and rep.getItemFromPos(i).getCommits() > L)
			projFound[m++] = rep.getItemFromPos(i);
	}
}


//eliminarea proiectelor care au noOfBranches*totalNoOfCommits = 0
void deleteProjZero(RepositoryArray& rep) {
	int i = 0;
	while (i < rep.dim()) {
		if (rep.getItemFromPos(i).getBranches() * rep.getItemFromPos(i).getCommits() == 0)
			rep.delElem(rep.getItemFromPos(i));
		else i++;
	}
}