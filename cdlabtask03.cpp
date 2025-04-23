 #include <iostream>
#include <cstring>  // Include this header to use strcmp
using namespace std;

bool isKeyword(const char *word) {
    const char *keywords[] = {"int", "float", "double", "char", "if", "else", "while", "for", "return", "void"};
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0) return true;
    }
    return false;
}

bool isOperator(char ch) {
    const char operators[] = {'+', '-', '*', '/', '=', '<', '>', '!'};
    for (int i = 0; i < 8; i++) {
        if (ch == operators[i]) return true;
    }
    return false;
}

bool isIdentifier(const char *word) {
    if (!((word[0] >= 'a' && word[0] <= 'z') || (word[0] >= 'A' && word[0] <= 'Z') || word[0] == '_')) return false;
    for (int i = 1; word[i] != '\0'; i++) {
        if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= '0' && word[i] <= '9') || word[i] == '_')) return false;
    }
    return true;
}

int main() {
    FILE *file = fopen("program.txt", "r");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char word[100];
    while (fscanf(file, "%99s", word) != EOF) {
        if (isKeyword(word)) {
            cout << word << " : Keyword" << endl;
        } else if (isOperator(word[0])) {
            cout << word << " : Operator" << endl;
        } else if (isIdentifier(word)) {
            cout << word << " : Identifier" << endl;
        } else {
            cout << word << " : Invalid Token" << endl;
        }
    }

    fclose(file);
    return 0;
}
