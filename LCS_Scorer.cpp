#include "include/LCS_Scorer.h"
#include "data/configs.h"
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
                if(X[i] == Y[j]) a0=c[i-1][j-1] + INCR;
                else  a0=c[i-1][j-1] - DECR;

                a0=maxf(a0, c[i][j-1] - DECR);
                a0=maxf(a0, c[i-1][j] - DECR);
                c[i][j]=a0;
                /* alikenessG[i][j][curIt]=c[i][j]; */
                /* double tempAns = (double ) a0 * a0 * MULT / YLEN; */
                double tempAns = 0;
                if(j == YLEN) tempAns = (double) a0 * a0 * MULT / (YLEN * i);
                CURMAXANSWER=maxf(CURMAXANSWER, tempAns);
            }
        }
        printf("x: %s, y:%s ans: %f\n", X.c_str(), Y.c_str(), CURMAXANSWER);
        return CURMAXANSWER;
    }
}
