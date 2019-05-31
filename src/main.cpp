#include <bits/stdc++.h>
#include "noerror.h"
/* #include "include/LCS_Scorer.h" */
#include "LCS_Scorer.h"
using namespace std;

string dna[50];
double overlaps[50][50], overlapsf[50][50];
int main() {
    freopen("../data/dna.txt", "r", stdin);
    ofstream alike; alike.open("../data/DNA Data.txt"); alike<<fixed<<setprecision ( 3 )<<endl;
    printf("testing\n");
    int noSeq;
    cin>>noSeq;

    for(int seq = 0; seq < noSeq; seq++) {
        cin>>dna[seq];
    }
    auto answer = LCS::init2(dna[0], dna[1]);
    //dna[0] is suffix
    for(int a = 0; a<answer.size(); a++) {
        
        for(int b = 0; b<a.size(); b++) {
            alike<<answer[a][b]<<" ";
        }
        cout<<endl<<endl;
    }

}
