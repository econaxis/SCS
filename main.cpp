#include <bits/stdc++.h>

#include "include/noerror.h"
#include "include/LCS_Scorer.h"

using namespace std;

string dna[50];
double overlaps[50][50], overlapsf[50][50];
extern double alikenessG[2][50][50];
int main() {
    freopen("data/dna.txt", "r", stdin);
    ofstream alike; alike.open("DNA Data.txt"); alike<<fixed<<setprecision ( 3 )<<endl;
    int noSeq;
    cin>>noSeq;

    for(int seq = 0; seq < noSeq; seq++) {
        cin>>dna[seq];
    }
    for(int i=0; i<noSeq; i++) {
        for(int k=0; k<noSeq; k++) {
            if(i==k) continue;

            //I contains suffix (to be cut) and K contains prefix (NO cut)
            double alikeness=0.0, alikenessf=0.0;
            for(int start=0; start<dna[i].length(); start++) {
                string _suffix = dna[i].substr(start, dna[i].length()-start);
                printf("suffix: %s\n", _suffix.c_str());
                double lcs_ans = LCS::lcs_compute (dna[k], _suffix);
                alikenessG [i][k][start] = lcs_ans;
                alikeness = LCS::maxf(alikeness, noe::maxOverlap(dna[k], _suffix));
                alikenessf= LCS::maxf(alikenessf, lcs_ans);
            }
            overlaps[i][k]=alikeness;
            overlapsf[i][k]=alikenessf;
        }
    }
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

    for(int i=0; i<noSeq; i++) {
        for(int k=0; k<noSeq; k++) {
            if(i==k) continue;
            alike<<"suffix: "<<dna[i].c_str()<<" prefix: "<<dna[k].c_str()<<endl;
            for(int start = 0; start < dna[i].length(); start ++ ) {
                alike<<alikenessG[i][k][start]<<" ";
            }
            alike<<endl;
        }
    }


}
