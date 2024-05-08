#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
public:
    Node* head;
    LinkedList() {//constructor
        head = NULL;
    }
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    Node* findMidpoint() {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* slow = head;//slow moves one step;
        Node* fast = head;//fast moves 2 step;
        // Move slow one step and fast two steps
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.insert(4);
    linkedList.insert(5);

    Node* midpoint = linkedList.findMidpoint();
    if (midpoint != NULL) {
        cout << "Midpoint of the linked list: " << midpoint->data << endl;
    } else {
        cout << "Linked list is empty" << endl;
    }

    return 0;
}

