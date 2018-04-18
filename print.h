#ifndef print_h
#define print_h
#include <iostream>
#include <stdexcept>
using namespace std;
void AddOne(char *, int);
void PrintNum(char *, int);

void PrintFrom1ToMaxNDigits(int n) {
	if (n<=0)
		throw invalid_argument("The n should be >= 1");

	char *num=new char [n];
	for (int i=0; i!=n; ++i) {
		num[i]='0';
	}
	bool finished=false;
	while (!finished) {
		finished=true;
		AddOne(num, n);
		PrintNum(num, n);
		for (int j=0; j!=n; ++j) {
			if (num[j]!='9') finished=false;
		}
	}

	delete []num;
}

void AddOne(char *num, int n) {
	//在num的基础上+1。
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
}

void PrintNum(char *num, int n) {
	bool zero=true;
	for (int index=0; index!=n; index++) {
		if (num[index]!='0') zero=false;
		if (!zero) {
			cout<<num[index];
		}
	}
	cout<<endl;
}
#endif
