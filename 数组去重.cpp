#include<iostream>
using namespace std;

int main() {
	int a[10];
	int b[10];

	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}

	b[0] = a[0];
	int k = 1;

	for (int i = 1; i < 10; i++) {
		bool isrepeat = false;
		for (int j = 0; j < k; j++) {
			if (a[i] == b[j]) {
				isrepeat = true;
				break;
			}
		}
		if (!isrepeat) {
			b[k] = a[i];
			k++;
		}
	}

	for (int i = 0; i < k; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	cout << "去重后元素个数：" << k << endl;

	return 0;

}