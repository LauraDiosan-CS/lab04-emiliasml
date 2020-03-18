#include "Repository.h"

RepositoryArray::RepositoryArray() { size = 0; }

RepositoryArray::~RepositoryArray() {
}

Project* RepositoryArray::getAll() {
	return elem;
}

int RepositoryArray::dim() {
	return size;
}

void RepositoryArray::addElem(Project p) {
	elem[size++] = p;
}

int RepositoryArray::findElem(Project p) {
	int i = 0;
	while (i < size) {
		if (p == elem[i]) return i; 
		i++;
	}
	return -1;
}

void RepositoryArray::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		elem[i] = elem[size - 1];
	size--;
}

void RepositoryArray::updateElem(Project p, char* g, int b, int c) {
	int i = findElem(p);
	elem[i].setGitPath(g);
	elem[i].setBranches(b);
	elem[i].setCommits(c);
}

Project RepositoryArray::getItemFromPos(int i) {
	return elem[i];
}




