#include <bits/stdc++.h>

using namespace std;
const int MINO=5;
int c[501][501];
int lcs_compute(string X, string Y) {
    for(int i=0; i<501; i++) for(int j=0; j<501; j++) c[i][j]=0;
    int maxans=0;
    printf("x: %s, y:%s \n", X.c_str(), Y.c_str());
    int m=X.length(), n=Y.length();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || j == 0)
            {	//default fill
                c[i][j] = 0;
                continue;
            }
            int a0, a1, a2;
            if(X[i] == Y[j]) a0=c[i-1][j-1]+10;
            else a0=c[i-1][j-1]-3;
            a0=max(a0, c[i][j-1]-3);
            a0=max(a0, c[i-1][j]-3);
            c[i][j]=a0;
            maxans=max(maxans, a0);
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(c[i][j]==-1) cout<<"$ ";
            else  cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxans;
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
    a1="$"+a1;
    set<pair<int,> answer;
    for(int i=0; i<a0.length(); i++) {
        printf("try %d\n", i);
        answer.insert(lcs_compute("$"+a0.substr(i, a0.length()-i), a1));
    }
    printf("max: %d\n", *answer.rbegin());
}
