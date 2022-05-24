#ifndef STRINGANALYZER_H
#define STRINGANALYZER_H

#include <iostream>
#include <vector>

class StringAnalyzer {
private:
    class node {
    public:
        node *next;
        node *prev;
        std::string value;

        explicit node(std::string value = std::string(), node *next = nullptr, node *prev = nullptr) {
            this->value = value;
            this->next = next;
            this->prev = prev;
        }
    };

    std::vector<char> separators;
    node *first;
    node *cur;
    int size;
public:
    StringAnalyzer();

    explicit StringAnalyzer(const std::string &str);

    void addSeparator(const char &c);

    void separate();

    int printCur();

    void resetCur();

    void clearSeparators();
};


#endif
