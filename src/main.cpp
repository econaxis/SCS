#include <bits/stdc++.h>
#include "noerror.h"
/* #include "include/LCS_Scorer.h" */
#include "LCS_Scorer.h"
using namespace std;

string dna[50];
double overlaps[50][50], overlapsf[50][50];
int main(int argc, char *argv[]) {
    printf("argv: %s\n", argv[1]);
    freopen(argv[1], "r", stdin);
    /* ofstream alike; alike.open("../data/DNA Data.txt"); alike<<fixed<<setprecision ( 3 )<<endl; */
    int noSeq;
    cin>>noSeq;
    for(int seq = 0; seq < noSeq; seq++) {
        cin>>dna[seq];
    }
    auto answer = LCS::init2(dna[0], dna[1]);
    //dna[0] is suffix
    /* for(int a = 0; a<answer.size(); a++) { */
    /*     for(int b = 0; b<answer[a].size(); b++) { */
    /*         cout<<answer[a][b]<<" "; */
    /*     } */
    /*     cout<<endl<<endl; */
    /* } */
    printf("done\n");
    return 0;
}
