#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}

//更简洁的写法（边输入边求和，省内存）
//不需要完整存储整个二维数组，输入一个数就累加一个，空间复杂度从 O(nm) 降到 O(1)，更高效
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long sum = 0;
    int x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            sum += x;
        }
    }

    cout << sum << endl;
    return 0;
}