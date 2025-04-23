#include <iostream>
using namespace std;

 
void helperFunction();


void helperFunction() {
    cout << "Helper function executed successfully." << endl;
}

int main() {
    cout << "Helper program running..." << endl;
    helperFunction();
    return 0;
}

