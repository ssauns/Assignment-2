#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include<cstddef>
#include<string>

using namespace std;

class SingleLinkedList {
private:
	struct Node {
		string data;
		Node* next;
		Node(const string& item) : data(item), next(nullptr) {}

	};

	Node* head = nullptr;
	Node* tail = nullptr;
	size_t num_items = 0;

public:
	SingleLinkedList();
	~SingleLinkedList();

	void push_front(const string& item);
	void push_back(const string& item);
	string pop_front();
	string pop_back();
	string front() const;
	string back() const;
	bool empty() const;
	void insert(size_t index, const string& item);
	bool remove(size_t index);
	size_t find(const string& item) const;
	size_t size() const;

}; 
#endif
