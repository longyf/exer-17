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
	if (index==n) {
		return;
	}
	int index2=index+1;
	for (int i=0; i!=10; ++i) {
		num[index]='0'+i;
		//这一个判断比较奇怪，其实我不知道为什么会这样，不过加上之后就能避免输出错误的结果了。
		if (index==n-1) PrintNum(num,n);
		SetElements(num,n,index2);
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
