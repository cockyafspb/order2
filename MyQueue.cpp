#include "MyQueue.h"

MyQueue::MyQueue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool MyQueue::IsEmpty() {
    if (size == 0)
        return true;
    else
        return false;
}

MyQueue::~MyQueue() {
    while (!IsEmpty()) {
        MyQueue::node *temp = head;
        int result = head->value;
        head = head->next;
        delete temp;
        temp = nullptr;
        size--;
    }
}

MyQueue& operator<<(MyQueue &q, const int &value) {
    MyQueue::node *temp = new MyQueue::node(value);
    if (q.size != 0) {
        q.tail->next = temp;
        q.tail = temp;
    } else {
        q.tail = temp;
        q.head = q.tail;
    }
    temp = nullptr;
    q.size++;
    return q;
}

MyQueue& operator>>(MyQueue &q, int &var) {
    if (q.head != nullptr) {
        MyQueue::node *temp = q.head;
        int result = q.head->value;
        q.head = q.head->next;
        delete temp;
        temp = nullptr;
        q.size--;
        var = result;
    }
    return q;
}
