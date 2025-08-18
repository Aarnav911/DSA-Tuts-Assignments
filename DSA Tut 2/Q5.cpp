#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int diag[4] = {1, 2, 3, 4};
    cout << "Diagonal (3,3) : " << diag[2] << endl;

    int tri[3*n-2] = {0};
    tri[0] = 5; tri[n-1] = 6; tri[2*n-2] = 7;
    cout << "Tri-diagonal (2,2) : " << tri[n-1] << endl;

    int lower[n*(n+1)/2] = {0};
    int i=3,j=2;
    lower[(i*(i-1))/2 + j-1] = 10;
    cout << "Lower (3,2) : " << lower[(i*(i-1))/2 + j-1] << endl;

    int upper[n*(n+1)/2] = {0};
    i=1; j=4;
    upper[(j*(j-1))/2 + i-1] = 11;
    cout << "Upper (1,4) : " << upper[(j*(j-1))/2 + i-1] << endl;

    int sym[n*(n+1)/2] = {0};
    i=4; j=2;
    sym[(i*(i-1))/2 + j-1] = 15;
    cout << "Symmetric (2,4) : " << sym[(i*(i-1))/2 + j-1] << endl;

    return 0;
}
