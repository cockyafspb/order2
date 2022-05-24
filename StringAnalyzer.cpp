#include "StringAnalyzer.h"

StringAnalyzer::StringAnalyzer() {
    first = new node();
    cur = first;
}

StringAnalyzer::StringAnalyzer(const std::string &str) {
    first = new node(str);
    cur = first;
}


void StringAnalyzer::addSeparator(const char &c) {
    separators.emplace_back(c);
    separate();
    std::cout << "string separated by a new symbol\n";
}

void StringAnalyzer::separate() {
    char sep = separators.back();
    auto ptr = first;
    while (ptr != nullptr) {
        size_t pos = ptr->value.find(sep);
        if (pos == std::string::npos){
            ptr = ptr->next;
        }
        else if (pos == 0 && ptr->value.length() > 1) {
            ptr->value = ptr->value.substr(1);
        } else if (pos == 0) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            auto tmp = ptr;
            ptr = ptr->next;
            delete tmp;

        } else {
            auto tmp = new node(ptr->value.substr(pos + 1), ptr->next, ptr);
            ptr->next = tmp;
            ptr->value = ptr->value.substr(0, pos);
            ptr = ptr->next;
        }
    }
}

int StringAnalyzer::printCur() {
    std::cout << cur->value << " | ";
    if (cur->next != nullptr) {
        cur = cur->next;
        return 1;
    } else {
        std::cout << "This was the last substring\n";
        return 0;
    }
}

void StringAnalyzer::resetCur() {
    cur = first;
}

void StringAnalyzer::clearSeparators() {
    separators.clear();
}
