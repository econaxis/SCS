#include "include/LCS_Scorer.h"
#include <bits/stdc++.h>

using namespace std;
double alikenessG[50][50][50], curIt=0;
namespace LCS
{
    double maxf(double a, double b) {
        if(a > b) return a;
        else return b;
    }

    //DP Array
    double c[501][501];

    double lcs_compute(string X, string Y) {
        //Y is SUFFIX n is lengthk
        for(int i=0; i<501; i++) for(int j=0; j<501; j++) c[i][j]=0;


        double CURMAXANSWER=0.0, a0;


        //As DP starts indexing at 1. Add lowest lexicograph character as placeholder for index 0
        X="$"+X;
        Y="$"+Y;


        const int XLEN=X.length(), YLEN=Y.length();
        /* XLEN = XLENin ( 2*n, XLEN ); */
        for(int i = 0; i <=XLEN; i++)
        {
            for(int j = 0; j <= YLEN; j++)
            {
                if(i == 0 || j == 0) {
                    c[i][j] = 1;
                    continue;
                }
                if(X[i] == Y[j]) a0=c[i-1][j-1]*1.5;
                else  a0=c[i-1][j-1]*0.8;

                a0=maxf(a0, c[i][j-1]*0.8);
                a0=maxf(a0, c[i-1][j]*0.8);
                c[i][j]=a0;
                printf("%d ", c[i][j]);
                /* alikenessG[i][j][curIt]=c[i][j]; */

                double tempAns = (double)c[i][j] / (2 * max(1, YLEN-1));
                CURMAXANSWER=maxf(CURMAXANSWER, tempAns);
            }
            cout<<endl;
        }
        printf("x: %s, y:%s ans: %f\n", X.c_str(), Y.c_str(), CURMAXANSWER);
        return CURMAXANSWER;
    }
}
