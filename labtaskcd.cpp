#include <iostream>
using namespace std;

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    int operatorCount = 0;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '=') {
            operatorCount++;
            cout << "Operator " << operatorCount << ": " << input[i] << endl;
        }
    }
    
    cout << "Number of operators: " << operatorCount << endl;
    return 0;
}
