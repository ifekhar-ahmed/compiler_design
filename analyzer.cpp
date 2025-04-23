#include <iostream>
#include <fstream>
#include <regex>
#include <cstdlib>  // For system commands

using namespace std;

// Function to check proper variable declaration
bool isValidVariableDeclaration(const string& line) {
    regex varPattern(R"((int|float|double|char|bool)\s+[a-zA-Z_]\w*\s*=?\s*[^;]*;)");
    return regex_match(line, varPattern);
}

// Function to check proper function declaration
bool isValidFunctionDeclaration(const string& line) {
    regex funcPattern(R"((int|float|double|void|char|bool)\s+[a-zA-Z_]\w*\s*\(.*\)\s*;)");
    return regex_match(line, funcPattern);
}

// Function to check proper function definition
bool isValidFunctionDefinition(const string& line) {
    regex funcDefPattern(R"((int|float|double|void|char|bool)\s+[a-zA-Z_]\w*\s*\(.*\)\s*\{)");
    return regex_match(line, funcDefPattern);
}

void analyzeFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (isValidVariableDeclaration(line))
            cout << "Valid Variable Declaration: " << line << endl;
        else if (isValidFunctionDeclaration(line))
            cout << "Valid Function Declaration: " << line << endl;
        else if (isValidFunctionDefinition(line))
            cout << "Valid Function Definition: " << line << endl;
    }

    file.close();
}

int main() {
    string filename = "input.cpp";
    analyzeFile(filename);

    // Call the helper program to execute further analysis
    system("g++ helper.cpp -o helper && ./helper");

    return 0;
}

