#include <iostream>
using namespace std;

template <typename T>
class LIFO {
    struct Node {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* topNode;

public:
    LIFO() : topNode(nullptr) {}

    ~LIFO() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& value) {
        topNode = new Node(value, topNode);
    }

    void pop() {
        if (isEmpty()) {
            return runtime_error("Stack is empty");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty()) {
            return runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }
};



template <typename T>
class FIFO {
    struct Node {
        T data;
        Node* next;

        Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* frontNode;
    Node* backNode;

public:
    FIFO() : frontNode(nullptr), backNode(nullptr) {}

    ~FIFO() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = backNode = newNode;
        }
        else {
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            return runtime_error("Queue is empty");
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr) {
            backNode = nullptr;
        }
    }

    T front() const {
        if (isEmpty()) {
            return runtime_error("Queue is empty");
        }
        return frontNode->data;
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }
};



int main() {
    LIFO<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack top: " << s.top() << endl;
    s.pop();
    cout << "Stack top after pop: " << s.top() <<endl;

    FIFO<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue front: " << q.front() << endl;
    q.dequeue();
    cout << "Queue front after dequeue: " << q.front() << endl;
}
