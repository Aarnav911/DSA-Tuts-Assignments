#include <iostream> 
using namespace std; 
int main() { 
int size; 
cout << "Enter the size of the array: "; 
while (!(cin >> size) || size <= 0) { 
cin.clear(); 
cin.ignore(10000, '\n'); 
cout << "Invalid size! Enter again: "; 
} 
int arr[size]; 
cout << "Enter the elements: "; 
for (int i = 0; i < size; i++) { 
while (!(cin >> arr[i])) { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Enter again: "; 
        } 
    } 
 
    int start = 0, end = size - 1; 
    while (start < end) { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
 
    cout << "Reversed array: "; 
    for (int i = 0; i < size; i++) cout << arr[i] << " "; 
    cout << endl; 
    return 0; 
} 
