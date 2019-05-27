#include <bits/stdc++.h>
#include "include/LCS_Scorer.h"

using namespace std;

int main() {
    freopen("dna.txt", "r", stdin);
    int n; cin>>n;
    printf("n:%d\n", n);
    string a0, a1;
    for(int i=0; i<n; i++) {
        cin>>a0;
        cin>>a1;
    }
    a1="$"+a1;
    set<pair<float, string>> answer;
    for(int i=0; i<a0.length(); i++) {
        printf("try %d\n", i);
        answer.insert({lcs_compute("$"+a0.substr(i, a0.length()-i), a1), a0.substr(i, a0.length()-i)});
    }
    printf("max: %f string: %s\n", (*answer.rbegin()).first , (*answer.rbegin()).second.c_str());
}
