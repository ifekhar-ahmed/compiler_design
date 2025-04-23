
#include <iostream>

using namespace std;

int main() {
    char input[100];
    cout << "Enter a line: ";
    cin.getline(input, 100);

    if (input[0] == '/' && input[1] == '/') {
        cout << "This is a single line comment." << endl;
    } else if (input[0] == '/' && input[1] == '*') {
        int len = 0;
        while (input[len] != '\0') {
            len++;
        }
        if (input[len - 2] == '*' && input[len - 1] == '/') {
            cout << "This is a multi line comment." << endl;
        } else {
            cout << "This is not a comment." << endl;
        }
    } else {
        cout << "This is not a comment." << endl;
    }

    return 0;
}
