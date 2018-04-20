#ifndef print_2_h
#define print_2_h
#include <iostream>
#include <stdexcept>
using namespace std;

void SetElements(char *, int, int);
void PrintNum(char *, int);

void PrintFrom1ToMaxNDigits(int n) {
	if (n<=0) 
		throw invalid_argument("The input n should be >= 1");

	char *num=new char [n];
	for (int i=0; i!=n; ++i) {
		num[i]='0';
	}

	SetElements(num,n,0);
	delete []num;
}

void SetElements(char *num,int n,int index) {

	//设置返回条件，表示已经处理完了最后一位。
	if (index==n) {
		PrintNum(num,n);
		return;
	}

	for (int i=0; i!=10; ++i) {
		num[index]='0'+i;
		SetElements(num,n,index+1);
	}
}

void PrintNum(char *num, int n) {
    //不要输出左边的零。比如，001输出1。
    bool zero=true;
    for (int index=0; index!=n; index++) {
        //从左至右，碰到非零值的时候就把zero变成false，然后开始输出后面的字符，>不管是不是零。
        if (num[index]!='0') zero=false;
        if (!zero) {
            cout<<num[index];
        }
    }
    cout<<endl;
}
#endif
