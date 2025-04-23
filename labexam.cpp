#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    // Open the input file
    ifstream file("programmm.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open file program.txt" << endl;
        return 1;
    }

    // Sets to store unique operators and preprocessors
    set<string> operators;
    set<string> preprocessors;

    string line;

    // Read the file line by line
    while (getline(file, line)) {
        // Check for preprocessors (#include, #define)
        if (line.find("#include") != string::npos) {
            preprocessors.insert("include");
        }
        if (line.find("#define") != string::npos) {
            preprocessors.insert("define");
        }

        // Check for operators
        // Addition operator +
        if (line.find("+") != string::npos) {
            operators.insert("addition");
        }

        // Subtraction operator -
        if (line.find("-") != string::npos) {
            operators.insert("subtraction");
        }

        // Multiplication operator *
        if (line.find("*") != string::npos) {
            operators.insert("multiplication");
        }

        // Assignment operator =
        if (line.find("=") != string::npos && line.find("==") == string::npos) {
            operators.insert("assignment");
        }
    }

    file.close();

    // Print the results
    int operatorCount = 1;
    for (const string& op : operators) {
        cout << "Operator-" << operatorCount << ": " << op << endl;
        operatorCount++;
    }

    cout << "Total number of the Operator: " << operators.size() << endl;

    int preprocessorCount = 1;
    for (const string& pp : preprocessors) {
        cout << "Preprocessor-" << preprocessorCount << ": " << pp << endl;
        preprocessorCount++;
    }

    cout << "Total number of preprocessor: " << preprocessors.size() << endl;

    return 0;
}
