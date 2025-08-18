#include <iostream> 
using namespace std; 
 
#define MAX_SIZE 100 
int arr[MAX_SIZE]; 
int n = 0; 
 
void createArray() { 
    cout << "Enter number of elements: "; 
    while (!(cin >> n) || n < 0 || n > MAX_SIZE) { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Enter a number between 0 and " << MAX_SIZE << ": "; 
    } 
    cout << "Enter " << n << " elements: "; 
    for (int i = 0; i < n; i++) { 
        while (!(cin >> arr[i])) { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Re-enter element " << i + 1 << ": "; 
        } 
    } 
} 
 
void displayArray() { 
    if (n == 0) { 
        cout << "Array is empty!" << endl; 
        return; 
    } 
    cout << "Array elements: "; 
    for (int i = 0; i < n; i++) cout << arr[i] << " "; 
    cout << endl; 
} 
 
void insertElement() { 
    if (n >= MAX_SIZE) { 
        cout << "Array is full! Cannot insert." << endl; 
        return; 
    } 
    int pos, val; 
    cout << "Enter position (0 to " << n << "): "; 
    while (!(cin >> pos) || pos < 0 || pos > n) { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid position! Enter again: "; 
    } 
    cout << "Enter value: "; 
    while (!(cin >> val)) { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Enter again: "; 
    } 
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1]; 
    arr[pos] = val; 
    n++; 
    cout << "Element inserted." << endl; 
} 
 
void deleteElement() { 
    if (n == 0) { 
        cout << "Array is empty!" << endl; 
        return; 
    } 
    int pos; 
    cout << "Enter position (0 to " << n - 1 << "): "; 
    while (!(cin >> pos) || pos < 0 || pos >= n) { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid position! Enter again: "; 
    } 
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1]; 
    n--; 
    cout << "Element deleted." << endl; 
} 
 
void linearSearch() { 
    if (n == 0) { 
        cout << "Array is empty!" << endl; 
        return; 
    } 
    int key; 
    cout << "Enter element to search: "; 
    while (!(cin >> key)) { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input! Enter again: "; 
    } 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) { 
            cout << "Element found at position " << i << endl; 
            return; 
        } 
    } 
    cout << "Element not found." << endl; 
} 
 
int main() { 
    int choice; 
    do { 
        cout << "\n---- MENU ----\n"; 
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n"; 
        cout << "Enter your choice: "; 
        if (!(cin >> choice)) { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid choice! Try again.\n"; 
            continue; 
        } 
        switch (choice) { 
            case 1: createArray(); break; 
            case 2: displayArray(); break; 
            case 3: insertElement(); break; 
            case 4: deleteElement(); break; 
            case 5: linearSearch(); break; 
            case 6: cout << "Exiting program.\n"; break; 
            default: cout << "Invalid choice! Try again.\n"; 
        } 
    } while (choice != 6); 
    return 0; 
} 
