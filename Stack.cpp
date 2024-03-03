#include <iostream>
#include <string>
#include<vector>


using namespace std;


class Stack {
private:
    vector<int> items;

public:
    void push(int item) {
        items.push_back(item);
    }

    int pop() {
        if (!empty()) {
            int popped_item = items.back();
            items.pop_back();
            return popped_item;
        }
        else {
            throw runtime_error("Stack is empty");
        }
    }

    int peek() const {
        if (!empty()) {
            return items.back();
        }
        else {
            throw runtime_error("Stack is empty");
        }
    }

    bool empty() const {
        return items.empty();
    }

    size_t size() const {
        return items.size();