#include <iostream>
#include <fstream>
#include <string>
#include <set>


using namespace std;

int main() {
    ifstream file("programmm.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open file programmm.txt" << endl;
        return 1;
    }

    set<string> operators;
    set<string> preprocessors;

    string line;

    while (getline(file, line)) {
        
        if (line.find("#include") != string::npos) {
            preprocessors.insert("include");
        }
        if (line.find("#define") != string::npos) {
            preprocessors.insert("define");
        }

         
        if (line.find("+") != string::npos) {
            operators.insert("addition");
        }
        if (line.find("-") != string::npos) {
            operators.insert("subtraction");
        }
        if (line.find("*") != string::npos) {
            operators.insert("multiplication");
        }
        if (line.find("=") != string::npos && line.find("==") == string::npos) {
            operators.insert("assignment");
        }
    }

    file.close();

    
    int varCount = 1;
    for (const string& op : operators) {
        cout << "Variable-" << varCount++ << ": " << op << endl;
    }
    cout << "Total number of variable: " << operators.size() << endl;

    
    int ppCount = 1;
    if (preprocessors.count("include")) {
        cout << "Preprocessor-" << ppCount++ << ": include" << endl;
    }
    if (preprocessors.count("define")) {
        cout << "Preprocessor-" << ppCount++ << ": define" << endl;
    }
    cout << "Total number of preprocessor: " << preprocessors.size() << endl;

    return 0;
}
