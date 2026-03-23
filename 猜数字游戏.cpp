#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	srand(time(0)); //随机数种子
	int ans = rand() % 100 + 1; //生成1~100的随机数
	int guess;
	cout << "猜数字（1~100)" << endl;

	while (true) {
		cin >> guess;
		if (guess == ans) {
			cout << "猜对了" << endl;
			break;
		}
		else if (guess > ans) {
			cout << "太大了" << endl;
		}
		else {
			cout << "太小了" << endl;
		}
	}
	return 0;
}