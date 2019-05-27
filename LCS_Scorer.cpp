#include "include/LCS_Scorer.h"
#include <bits/stdc++.h>

using namespace std;

float maxf(float a, float b) {
    if(a > b) return a;
    else return b;
}

//DP Array
int c[501][501];

float lcs_compute(string X, string Y) {
    for(int i=0; i<501; i++) for(int j=0; j<501; j++) c[i][j]=0;
    float maxans=0.0;
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
            if(i==m-1) maxans=maxf(maxans, a0/(sqrt(i+j)));
        }
    }
    return maxans;
}
