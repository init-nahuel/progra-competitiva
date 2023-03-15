#include <iostream>

using namespace std; 

int main() {
    string str;
    cin >> str;
    int n = str.length();
    int A=0, B=0, i=0;
    while (i<n-1) {
        if (str[i] == 'A'){
            A+=str[i+1];
        }
        else {
            B+=str[i+1];
        }
        i+=2;
    }
    string result = (A>B) ? "A" : "B";
    cout << result << endl;
    return 0;
}