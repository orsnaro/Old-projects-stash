//============================================================================
// Name        : cpp4kids_s7(functions)....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice (<3)
// Description : solving cpp4kids H.Ws (functions) C++, Ansi-style
//============================================================================
//INCLUDES
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


//FUNCTIONS

	//---------------------------------------------------------------------------------
	//h.w2 cpp4kids 29#

//string rev_str(const string &str) {
//
//	char str2[str.size()+1]={0}; //also works [str.size()]
//	int mx_size = str.size();
//
//	for (int i = 0; i < mx_size; ++i)
//		str2[i] = str[mx_size - 1 - i];
//
//	return (str2);
//}

	//---------------------------------------------------------------------------------
	//h.w6 cpp4kids 29#


bool is_prime(int n) {

	int m = 0;
	bool flag = 1;
	m = n >> 1; // equal to n/2 but faster

	for (int i = 2; i <= m; ++i) {
		if (n % i == 0) {
			flag = 0;
			return (flag);
			break;
		}
	}

	if (flag == 1)
		return (flag);
	else
		return (flag);

}

int nth_prime(int n) {

	static int cntr;
	int i = 2;
	bool flag;

	while (cntr < n) {


		flag = is_prime(i);
		if (flag == true)
			cntr++;

		i++;
	}

	return (i-1);
}







int main() {
	//---------------------------------------------------------------------------------
	//h.w2 cpp4kids 29#

	/*
	string txt;
	cin >> txt;
	const string main_str = txt;

	cout << rev_str(main_str) << endl;
	*/


	//---------------------------------------------------------------------------------
	//h.w6 cpp4kids 29#

//int n;
//cin >> n;
//cout<< nth_prime(n);


	//---------------------------------------------------------------------------------
	//h.w7 cpp4kids 29#


	return (0);
}


