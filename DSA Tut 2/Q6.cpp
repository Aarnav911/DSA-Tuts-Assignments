#include <iostream>
using namespace std;

void read(int a[20][3], int &n, int &r, int &c) {
    cout<<"Enter rows cols nonzeros: ";
    cin>>r>>c>>n;
    cout<<"Enter row col val:\n";
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
}

void showTriplet(int a[20][3], int n) {
    for(int i=0;i<n;i++)
        cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
}

void showMatrix(int a[20][3], int n, int rows, int cols) {
    int mat[20][20] = {0};
    for(int i=0; i<n; i++)
        mat[a[i][0]][a[i][1]] = a[i][2];

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void transpose(int a[20][3], int t[20][3], int n, int r, int c) {
    for(int i=0;i<n;i++){
        t[i][0]=a[i][1];
        t[i][1]=a[i][0];
        t[i][2]=a[i][2];
    }
}

void add(int a[20][3], int b[20][3], int c[20][3], int n1, int n2, int &n3) {
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1]))
            for(int m=0;m<3;m++) c[k][m]=a[i][m], i++, k++;
        else if(b[j][0]<a[i][0] || (b[j][0]==a[i][0] && b[j][1]<a[i][1]))
            for(int m=0;m<3;m++) c[k][m]=b[j][m], j++, k++;
        else {
            c[k][0]=a[i][0]; c[k][1]=a[i][1];
            c[k][2]=a[i][2]+b[j][2];
            i++; j++; k++;
        }
    }
    while(i<n1) for(int m=0;m<3;m++) c[k][m]=a[i][m], i++, k++;
    while(j<n2) for(int m=0;m<3;m++) c[k][m]=b[j][m], j++, k++;
    n3=k;
}

void multiply(int a[20][3], int b[20][3], int c[20][3], int n1, int n2, int &n3) {
    n3=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i][1]==b[j][0]){
                int r=a[i][0], col=b[j][1], val=a[i][2]*b[j][2], f=0;
                for(int m=0;m<n3;m++)
                    if(c[m][0]==r && c[m][1]==col){ c[m][2]+=val; f=1; break; }
                if(!f){ c[n3][0]=r; c[n3][1]=col; c[n3][2]=val; n3++; }
            }
        }
    }
}

int main() {
    int a[20][3], b[20][3], t[20][3], c[20][3];
    int n1,n2,n3,r1,c1,r2,c2;
    cout<<"First Matrix:\n"; read(a,n1,r1,c1);
    cout<<"Second Matrix:\n"; read(b,n2,r2,c2);

    cout<<"\nMatrix A (full):\n"; showMatrix(a,n1,r1,c1);
    cout<<"\nMatrix B (full):\n"; showMatrix(b,n2,r2,c2);

    cout<<"\nTranspose of A (triplet):\n"; transpose(a,t,n1,r1,c1); showTriplet(t,n1);
    cout<<"\nTranspose of A (full):\n"; showMatrix(t,n1,c1,r1);

    cout<<"\nAddition (A+B) (triplet):\n"; add(a,b,c,n1,n2,n3); showTriplet(c,n3);
    cout<<"\nAddition (A+B) (full):\n"; showMatrix(c,n3,r1,c1);

    cout<<"\nMultiplication (A*B) (triplet):\n"; multiply(a,b,c,n1,n2,n3); showTriplet(c,n3);
    cout<<"\nMultiplication (A*B) (full):\n"; showMatrix(c,n3,r1,c2);
}
