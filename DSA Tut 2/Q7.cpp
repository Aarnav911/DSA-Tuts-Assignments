#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for(int i=0;i<n1;i++) left[i]=arr[l+i];
    for(int j=0;j<n2;j++) right[j]=arr[m+1+j];

    int i=0, j=0, k=l;
    long long inv=0;

    while(i<n1 && j<n2){
        if(left[i]<=right[j]) arr[k++]=left[i++];
        else {
            arr[k++]=right[j++];
            inv += (n1-i);  
        }
    }
    while(i<n1) arr[k++]=left[i++];
    while(j<n2) arr[k++]=right[j++];
    return inv;
}

long long countInversions(int arr[], int l, int r) {
    long long inv=0;
    if(l<r){
        int m=(l+r)/2;
        inv+=countInversions(arr,l,m);
        inv+=countInversions(arr,m+1,r);
        inv+=mergeAndCount(arr,l,m,r);
    }
    return inv;
}

int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Number of inversions: "<<countInversions(arr,0,n-1);
    return 0;
}
