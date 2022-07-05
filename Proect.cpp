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
}
void printlist(size_head*& list, int n) {
	struct spis* tmp = list->head;
	cout << "Элементы списка: " << endl;
	for (int i = 0; i < list->size; i++) {
		for (int j = 0; j < n; j++) {
			cout << tmp->ver[j] << " ";
		}
		tmp = tmp->next;
		cout << endl;
	}
}
void step(size_head*& list, int n, int m, vector<int>& stepen) {
	struct spis* tmp = list->head;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			stepen[i] += tmp->ver[i];
			tmp = tmp->next;
		}
		tmp = list->head;
	}
	cout << "Степени" << endl;
	for (int i = 0; i < n; i++) {
		cout << stepen[i] << " ";
	}
	cout << endl;
}
void sort(size_head*& list, int n, int m, vector<int>& stepen, vector<int>& ind) {
	struct spis* sp = list->head;
	vector<int> tmp(n);
	int temp1, temp2;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (stepen[j] > stepen[j + 1]) {
				temp1 = stepen[j];
				temp2 = ind[j];
				stepen[j] = stepen[j + 1];
				ind[j] = ind[j + 1];
				stepen[j + 1] = temp1;
				ind[j + 1] = temp2;
			}
		}
	}


