#ifndef print_h
#define print_h
#include <iostream>
#include <stdexcept>
using namespace std;
bool AddOne(char *, int);
void PrintNum(char *, int);

void PrintFrom1ToMaxNDigits(int n) {
	if (n<=0)
		throw invalid_argument("The n should be >= 1");

	char *num=new char [n];
	for (int i=0; i!=n; ++i) {
		num[i]='0';
	}
	while (true) {
		if (AddOne(num, n)) {
			PrintNum(num, n);
		}
		else {
			//表示已经达到了最大位。
			break;
		}
	}

	delete []num;
}

bool AddOne(char *num, int n) {
	//在num的基础上+1。
	char temp=num[0];
	//不用进位。
	if (num[n-1]!='9') {
		num[n-1]++;
	}
	else {
		int index=n-1;
		while (num[index]=='9') {
			num[index]='0';
			index--;
		}
		num[index]++;
	}
	//判断是否已经达到了最大值。
	if (temp=='9'&&num[0]=='0') {
		return false;
	}
	else {
		return true;
	}
}

void PrintNum(char *num, int n) {
	//不要输出左边的零。比如，001输出1。
	bool zero=true;
	for (int index=0; index!=n; index++) {
		//从左至右，碰到非零值的时候就把zero变成false，然后开始输出后面的字符，不管是不是零。
		if (num[index]!='0') zero=false;
		if (!zero) {
			cout<<num[index];
		}
	}
	cout<<endl;
}
#endif
