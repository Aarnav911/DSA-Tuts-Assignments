#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str = "Programming";

    string concatStr = str + "Language";
    cout << "Concatenation: " << concatStr << endl;

    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    cout << "Reversed: " << revStr << endl;

    string noVowels = "";
    for (char c : str) {
        char ch = tolower(c);
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'))
            noVowels += c;
    }
    cout << "Without vowels: " << noVowels << endl;

    string arr[] = {str, "Language", "AI", "Backend"};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    char c = str[0];
    if (c >= 'A' && c <= 'Z') c += 32;
    cout << "First character in lowercase: " << c << endl;

    return 0;
}
