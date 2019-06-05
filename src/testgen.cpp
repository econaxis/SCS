#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]) {
    printf("inputs: %s %s\n", argv[1], argv[2]);
    string outPath = argv[1];
    ofstream out; out.open (outPath, ofstream::app);
    int OVER = stoi(argv[2]);
    const int NONOVER = 400, TOTAL = NONOVER + OVER;
    out<<"20\n";
    float err_arr[20];
    for(int i=1; i<=20; i++) {
        err_arr[i-1] = 0.025*i;
    }
    for(int a0 = 0; a0 <20; a0++) { 
        double ERR = err_arr [a0];
        printf("ERR: %f\n", ERR);
        srand(time(NULL) + a0*9);
        vector<int> seq1, seq2;
        seq1.resize (NONOVER + OVER); seq2.resize(NONOVER + OVER);
        for(int i = 0; i<NONOVER; i++) {
            seq1[i] = rand() % 4 +1;
            seq2[i+NONOVER] = rand() %4 + 1;
        }
        int FRQ = 1.00 / ERR; 
        for(int i=0; i<OVER; i++) {
            seq1[i+NONOVER] = rand()%4 +1;
            if(rand() % FRQ == 1) {
                seq2[i] = rand() %4 +1;
            } else {
                seq2[i] = seq1[i+NONOVER];
            }
        }
        for(int i = 0; i<TOTAL; i++) {
            if(seq1[i]==0) continue;
            cout<<seq1[i];
            out<<seq1[i];
        }
        cout<<endl;
        out<<endl;
        for(int i = 0; i<TOTAL; i++) {
            if(seq2[i]==0) continue;
            cout<<seq2[i];
            out<<seq2[i];
        }
        out<<endl;}
}
