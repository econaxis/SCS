#include "include/LCS_Scorer.h"
#include <bits/stdc++.h>

using namespace std;
namespace LCS
{
    double maxf(double a, double b) {
        if(a > b) return a;
        else return b;
    }

    //DP Array
    int c[501][501];

    double lcs_compute(string X, string Y) {
        //Y is SUFFIX n is lengthk
        for(int i=0; i<501; i++) for(int j=0; j<501; j++) c[i][j]=0;
        double maxans=0.0, a0;
        X="$"+X;
        Y="$"+Y;
        int m=X.length(), n=Y.length();
        /* m = min ( 2*n, m ); */
        for(int i = 0; i <=m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0 || j == 0) {
                    c[i][j] = 0;
                    continue;
                }
                if(X[i] == Y[j]) a0=c[i-1][j-1]+2;
                else  a0=c[i-1][j-1]-1;

                a0=maxf(a0, c[i][j-1]-1);
                a0=maxf(a0, c[i-1][j]-1);
                c[i][j]=a0;
                printf("%d ", c[i][j]);


                double tempAns = (double)c[i][j] / (2 * max(1, n-1));
                maxans=maxf(maxans, tempAns);
            }
            cout<<endl;
        }
        printf("x: %s, y:%s ans: %f\n", X.c_str(), Y.c_str(), maxans);
        return maxans;
    }
}
