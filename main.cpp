// func - find max elem in arr
// class - queue
#include <iostream>

template<typename T, int N>
T find_max(T (&arr)[N]) {
    T max = T();
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template<int N, typename T>
class MyQueue {
    class node {
    public:
        node *next;
        T value;

        node(T value = T(), node *next = nullptr) {
            this->value = value;
            this->next = next;
        }
    };

    node *head;
    node *tail;
    int size;

public:
    MyQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool IsEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    void push(T value) {
        if (size == N) {
            throw std::invalid_argument("queue overflow");
        }

        node *temp = new node(value);
        if (size != 0) {
            tail->next = temp;

            tail = temp;
        } else {
            tail = temp;

            head = tail;
        }

        temp = nullptr;

        size++;
    }

    T pop() {
        if (this->head != nullptr) {
            node *temp = this->head;
            T result = this->head->value;
            head = head->next;
            delete temp;
            temp = nullptr;
            size--;
            return result;
        }
        throw std::invalid_argument("poping empty queue");
    }

    ~MyQueue() {
        while (!IsEmpty())
            pop();
    }

};

int main() {
    int arr[] = {1, 3, 5, 88, 13, -111, 2};
    std::cout << find_max(arr) << std::endl;
    MyQueue<3, int> q;
    try {
        q.push(3);
        q.push(2);
        q.push(4);
        //q.push(5);
    }
    catch (std::invalid_argument exception) {
        std::cerr << exception.what() << std::endl;
    }

    try {
        q.pop();
        q.pop();
        q.pop();
        q.pop();
    }
    catch (std::invalid_argument exception) {
        std::cerr << exception.what() << std::endl;
    }
    return 0;
}
