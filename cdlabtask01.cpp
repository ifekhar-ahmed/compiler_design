 #include <iostream>

using namespace std;

int main() {
    char input[100];
    cout << "Enter an expression: ";
    cin.getline(input, 100);

    int count = 0;
    char operators[] = "+-*/%=<>!&|^";

    int i = 0;
    while (input[i] != '\0') {
        for (int j = 0; operators[j] != '\0'; j++) {
            if (input[i] == operators[j]) {
                count++;
                cout << "operator" << count << " : " << input[i] << endl;
                break;
            }
        }
        i++;
    }

    cout << "Number of operators = " << count << endl;
    return 0;
}
