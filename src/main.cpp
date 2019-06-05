#include <iostream> 
#include <vector>
#include <stdio.h>
#include <string>
#include <fstream>
#include "noerror.h"
#include "LCS_Scorer.h"
using namespace std;

string dna[50];
int main(int argc, char *argv[]) {
    printf("argv: %s\n", argv[1]);
    freopen(argv[1], "r", stdin);
    ofstream alike; alike.open("../data/DNA Data.txt");
    int noSeq;
    cin>>noSeq;
    for(int seq = 0; seq < noSeq; seq++) {
        cin>>dna[0]>>dna[1];
        pair<double, int> bestAns = {-10000, -1};
        LCS::init2(dna[0], dna[1], bestAns);
        printf("%f %d\n", bestAns.first, bestAns.second);
    }
    return 0;
}
