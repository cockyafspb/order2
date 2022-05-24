#ifndef MYQUEUE_H
#define MYQUEUE_H


class MyQueue {
private:
    class node {
    public:
        node *next;
        int value;

        node(int value = int(), node *next = nullptr) {
            this->value = value;
            this->next = next;
        }
    };

    node *head;
    node *tail;
    int size;
public:
    MyQueue();

    bool IsEmpty();

    friend MyQueue& operator<<(MyQueue &q, const int &value);

    friend MyQueue& operator>>(MyQueue &q, int &var);

    ~MyQueue();
};


#endif
