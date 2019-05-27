#include <bits/stdc++.h>
#include "include/noerror.h"
#include "include/LCS_Scorer.h"

using namespace std;

string dna[50];
float overlaps[50][50], overlapsf[50][50];
int main() {
    freopen("data/dna.txt", "r", stdin);
    int noSeq;
    cin>>noSeq;

    for(int seq = 0; seq < noSeq; seq++) {
        cin>>dna[seq];
    }
    for(int i=0; i<noSeq; i++) {
        for(int k=0; k<noSeq; k++) {
            if(i==k) continue;

            //I contains suffix (to be cut) and K contains prefix (NO cut)
            /* float alikeness=0.0, alikenessf=0.0; */
            for(int start=0; start<dna[i].length(); start++) {
                string _suffix = dna[i].substr(start, dna[i].length()-start);
                alikeness = LCS::maxf(alikeness, noe::maxOverlap(dna[k], _suffix));
                alikenessf= LCS::maxf(alikenessf, LCS::lcs_compute(dna[k], _suffix));
            }
            overlaps[i][k]=alikeness;
            overlapsf[i][k]=alikenessf;
        }
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
    for(int i=0; i<noSeq; i++) {
        for(int k=0; k<noSeq; k++) {
            cout<<overlaps[i][k]<<" ";
        }
        printf("\n");
    }
    printf("----------------------------\n");
    for(int i=0; i<noSeq; i++) {
        for(int k=0; k<noSeq; k++) {
            cout<<overlapsf[i][k]<<" ";
        }
        printf("\n");
    }
}
