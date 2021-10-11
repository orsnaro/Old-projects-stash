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

/*
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

*/

	//---------------------------------------------------------------------------------
	//h.w7 cpp4kids 29#


bool isValid_ptrn(int str_pos, int ptrn_length, string in, string find) {

		for (int i = str_pos, cntr = 0; i < ptrn_length; ++i) {

			if (in[i] == find[i])
				cntr++;

			else {

				return (false);
				break;
			}
		}

		return (true);
	}

bool starts_at(string in, string find, int at) {

	static int i, cntr;
	bool ptrn_begin=false;
	bool valid;


	if (find.size() == 1) {
		if (in[at] == find)
			return (0); //true
		else
			return (1); //false
	}

	else

	while (i < in.size()-1) {

	if ( in[i] == find[i] && ptrn_begin==false ) {

			cntr++;
			ptrn_begin=true;
			valid = isValid_ptrn(i,find.size(), in , find );

			if(valid== true){

			}
	}
		i++;
}

string  replace_str(string in, string find, string to) {

	if (find.length() <= 0 || to.length() < 0)
		return 0;//false

	string final;
	for (int i = 0; i < in.size(); ++i) {



	}

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


