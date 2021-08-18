//============================================================================
// Name        : cpp4kids_s5....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice
// Description : solving cpp4kids H.W (while\for loops) C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

//h.w1 14#

	/*

	 int a,b,i;
	 cin>>a>>b>>i;
	 i=a;

	 while(i<=b){
	 cout<<i<<"\n";
	 i++;
	 }

	 */






//============================================================================
//h.w 3,4,5 14#

	/*

	int N, taps, stars;

	cin >> N;
	static int i, j;

	while (i < N) {

		stars = 1 + 2 * i;
		taps = N - (i + 1); //try put this two eqn outside while and see if they update value :D.

			while (j <= taps) {
				cout << " ";
				j++;
			}


		j = 0;
		while (j < stars) {
			cout << '*';
			j++;
		}
		cout << "\n";
		j = 0;
		i++;
	}

	j = 0;
	i = N - 1;
	while (i >= 0) {

		stars = 1 + 2 * i;
		taps = N - (i + 1);

		while (j <= taps) {
			cout << " ";
			j++;
		}

		j = 0;
		while (j < stars) {
			cout << '*';
			j++;
		}

		cout << "\n";
		j = 0;
		i--;
	}
*/
//============================================================================
//h.w7 14#
	/*
	 static int n, i;

	 cin >> n;

	 if (n < 0 || n > 200) {
	 cout << "error ,retry";
	 return 0;
	 }
	 while (i <= n) {
	 i++;
	 if (i % 8 == 0 || (i % 4 == 0 && i % 3 == 0))
	 cout << i << "\t";
	 }
	 */
	//---------------------------------------------------------------------------------
	//h.w9 cpp4kids 14#
	/*
	string no_dtct;
	static int i, n;

	cin >> n;
	if (n <= 0) {
		cout << "error ,retry";
		return 0;
	}

	while (i < n) {

		cin >> no_dtct;

		if (no_dtct == "no" || no_dtct == "No" || no_dtct == "nO"
				|| no_dtct == "NO")
			cout << no_dtct << " ";
		i++;
	}
*/

	//---------------------------------------------------------------------------------
	//h.w11 cpp4kids 14#

	/*
	int min, cases, num_cntr, num, i, j;
	cin >> cases;

	i = 0;
	j = 0;

	while (i < cases) {
		i++;
		cin >> num_cntr;
		if (num_cntr == 0) {
			cout << 0;

			continue;
		}

		cin>>num;
		min = num;

		while (j < num_cntr - 1) {

			cin >> num;
			if (min > num)

				min = num;
			j++;
		}

		cout << min << endl;
		j = 0;

	}
	*/

	//---------------------------------------------------------------------------------
					//h.w131 cpp4kids 14#







	return 0;
}
