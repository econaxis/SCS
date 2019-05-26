#include <bits/stdc++.h>

using namespace std;
const int MINO=5;
string dna[1000];
double overlap[1000][1000];
int c[51][51];
char b[51][51];
int lcs_compute(string X, string Y) {
    printf("x: %s, y:%s \n", X.c_str(), Y.c_str());
    int m=X.length(), n=Y.length();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0)
            {	//default fill
                c[i][j] = 0;
                b[i][j] = '/';
                continue;
            }
            int a0, a1, a2;
            if(X[i] == Y[j]) a0=c[i-1][j-1]+2;
            else a0=c[i-1][j-1]-1;
            a0=max(a0, c[i][j-1]-1);
            a0=max(a0, c[i-1][j]-1);
            c[i][j]=a0;
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(c[i][j]==-1) cout<<"$ ";
            else  cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return c[m][n];
}
int main() {
    freopen("dna.txt", "r", stdin);

    int n; cin>>n;
    printf("N:%d\n", n);
    string a0, a1;
    for(int i=0; i<n; i++) {
        cin>>a0;
        cin>>a1;
    }
    a0="$"+a0;
    a1="$"+a1;
    printf("max overlap: %d\n", lcs_compute(a0, a1));
}
