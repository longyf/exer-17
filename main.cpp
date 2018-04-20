#include <iostream>
//#include "print.h"
#include "print_2.h"
//#include "Print1ToMaxOfNDigits.h"
using namespace std;

void test1() {
	try {
		PrintFrom1ToMaxNDigits(3);
	}
	catch (invalid_argument e) {
		cout<<e.what()<<endl;
	}
}

void test2() {
    try {
        PrintFrom1ToMaxNDigits(-1);
    }
    catch (invalid_argument e) {
        cout<<e.what()<<endl;
    }
}

int main() {
	test1();
	test2();
	return 0;
}
