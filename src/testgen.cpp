#include <bits/stdc++.h>

using namespace std;

int main() {
    int n=20;
    cout<<n<<endl;
    srand (time(NULL));

    string sequence(60, '0');

    for(int i=0; i<60; i++) {
        sequence[i]=rand() % 10 + '0';
    }
    while(n--) {
        int start=rand()%10;
        cout<<sequence.substr(start, start+10);
        cout<<endl;
    }
}
