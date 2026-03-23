#include<bits/stdc++.h>
using namespace std;

int main() {
    int high[10];
    for (int i = 0; i < 10; i++) {
        cin >> high[i];
    }
    int peo_high;
    cin >> peo_high;
    int peo_higher = peo_high + 30;
    int count = 0;
    for (int j = 0; j < 10; j++) {
        if (high[j] <= peo_higher) {
            count++;
        }
    }
    cout << count << endl;
}