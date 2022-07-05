#include<iostream>
#include<vector>

using namespace std;
struct spis {
	vector<int> ver;
	struct spis* next;
};
struct size_head {
	size_t size;
	struct spis* head;
};
void addElem(size_head*& list, vector<int> matr, int n) {
	spis* newElem = new spis;
	for (int i = 0; i < n; i++) {
		newElem->ver.push_back(matr[i]);
	}
	if (list->size == 0) {
		list->head = newElem;
		list->head->next = list->head;
	}
	else {
		struct spis* temp;
		temp = list->head;
		list->head = newElem;
		newElem->next = temp;
	}
	++list->size;
