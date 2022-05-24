#include "StringAnalyzer.h"
int main() {
    StringAnalyzer anal("Hello World");
    anal.addSeparator('l');
    while (anal.printCur()){}
    anal.resetCur();
    anal.addSeparator('o');
    while (anal.printCur()){}
    anal.clearSeparators();

    StringAnalyzer anal1("abbcabccababbaacbacb");
    anal1.addSeparator('c');
    while(anal1.printCur()){}
    return 0;
}