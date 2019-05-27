#include "include/LCS_Scorer.h"
#include <bits/stdc++.h>

using namespace std;
namespace LCS
{
    float maxf(float a, float b) {
        if(a > b) return a;
        else return b;
    }

    //DP Array
    int c[501][501];

    float lcs_compute(string X, string Y) {
        for(int i=0; i<501; i++) for(int j=0; j<501; j++) c[i][j]=0;
        float maxans=0.0;
        int m=X.length(), n=Y.length();
        for(int i = 0; i <=m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0)
                {   //default fill
                    c[i][j] = 0;
                    continue;
                }
                float a0;
                if(X[i] == Y[j]) a0=c[i-1][j-1]+6;
                else a0=c[i-1][j-1]-3;
                a0=maxf(a0, (float)c[i][j-1]-3);
                a0=maxf(a0, (float)c[i-1][j]-3);
                c[i][j]=a0;
                printf("answering %d l:%d\n", a0, Y.length());
                maxans=maxf(maxans, a0/((float)Y.length()));
            }
            printf("x: %s, y:%s ans: %f\n", X.c_str(), Y.c_str(), maxans);
            /* for(int i=1; i<=m; i++) { */
            /*     cout<<endl; */
            /*     for(int j=1; j<=m; j++) cout<<c[i][j]<<" "; */
            /* } */
            return maxans;
        }
    }
}
