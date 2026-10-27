#include <iostream>
#include <vector>

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int i) {
        Node* curr = head;
        int index = 0;
        
        while (curr != nullptr) {
            if (index == i) {
                return curr->val;
            }
            curr = curr->next;
            index++;
        }
        
        return -1;
    }
    void insertHead(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    bool remove(int i) {
        if (head == nullptr) return false;
        if (i == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return true;
        }
        Node* curr = head;
        int index = 0;
        while (curr != nullptr && index < i - 1) {
            curr = curr->next;
            index++;
        }
        if (curr == nullptr || curr->next == nullptr) {
            return false;
        }

        Node* nodeToRemove = curr->next;
        curr->next = nodeToRemove->next;
        if (nodeToRemove == tail) {
            tail = curr;
        }

        delete nodeToRemove;
        return true;
    }
    std::vector<int> getValues() {
        std::vector<int> values;
        Node* curr = head;
        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};