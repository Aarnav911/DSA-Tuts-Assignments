#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
    if (arr[i] == target){
    return i;}}
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {return mid;}
        else if (arr[mid] < target) {low = mid + 1;}
        else {high = mid - 1;}
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    int lin = linearSearch(arr, n, target);
    if (lin != -1) cout << "Linear Search: Found at index " << lin << endl;
    else cout << "Linear Search: Not found" << endl;

    int bin = binarySearch(arr, n, target);
    if (bin != -1) cout << "Binary Search: Found at index " << bin << endl;
    else cout << "Binary Search: Not found" << endl;

    return 0;
}
