// CS303Assign2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SingleLinkedList.h"


SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr) {}

SingleLinkedList::~SingleLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

size_t SingleLinkedList::size() const {
    return num_items;
}

//push item to the front of the list
void SingleLinkedList::push_front(const string& item) {
    Node* new_node = new_node;
    if (!head) {
        head = tail = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    ++num_items;
}

//pop front item from the list
string SingleLinkedList::pop_front() {
    if (!head) {
        throw runtime_error("list is empty");
    }
    Node* temp = head;
    head = head->next;
    string popped_item = temp->data;
    delete temp;
    --num_items;
    return popped_item;
}
//Return front item of the list
string SingleLinkedList::front() const {
    if (!head) {
        throw runtime_error("List is empty");
    }
    return head->data;
}
//check if list is empty

bool SingleLinkedList::empty() const {
    return num_items == 0;
}

void SingleLinkedList::insert(size_t index, const string& item) {
    if (index > num_items) {
        push_back(item);
    }
    else if (index == 0) {
        push_front(item);
    }
    else {
        Node* new_node = new Node(item);
        Node* temp = head;
        for (size_t i = 1; i < index; ++i) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        ++num_items;
    }
}
bool SingleLinkedList::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node* temp = head;
        for (size_t i = 1; i < index; ++i) {
            temp = temp->next;
        }
        Node* to_remove = temp->next;
        temp->next = to_remove->next;
        delete to_remove;
        --num_items;
    }
    return true;
}

size_t SingleLinkedList::find(const string& item) const {
    Node* temp = head;
    size_t index = 0;
    while (temp) {
        if (temp->data == item) {
            return index;
        }

        temp = temp->next;
        ++index;
    }
    return num_items;
}


int main()
{
    SingleLinkedList myList;

    myList.push_front("rock");
    myList.push_back("paper");
    myList.push_back("scissors");

    cout << "front element: " << myList.front() << endl;

    myList.pop_front();

    cout << "Is the list empty? " << (myList.empty() ? "yes" : "no") << endl;

    //insert am element at a specific index
    myList.insert(3, "shoot");

    //find postiom of an item
    string search_item = "paper";
    size_t position = myList.find(search_item);
    if (position < myList.size()) {
        cout << "Item " << search_item << "found at position" << position << endl;
    }
    else {
        cout << "item " << search_item << "not found in the list" << endl;
    }

    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Stack size: " << myStack.size() << std::endl;
    std::cout << "Top item: " << myStack.peek() << std::endl;

    while (!myStack.empty()) {
        std::cout << "Popped item: " << myStack.pop() << std::endl;
    }

    return 0;
    


