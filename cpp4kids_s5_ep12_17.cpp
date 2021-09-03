//============================================================================
// Name        : cpp4kids_s5....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice
// Description : solving cpp4kids H.W (while\for loops) C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
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
	//!!!NOT FROM HOME WORKS (TEST FOR 3n+1 CONJECTURE)!!!!
/*
	long long int x, temp;
	cout << "enter number to check the conjecture!" << endl;
	cin >> x;
	cout << LLONG_MAX;
	for (;;) {

		if (x % 2 == 0) {
			x = x / 2;
			cout << x << endl;
			if (x == 1) {
				cout << " we entered the loop! :(" << endl;
				temp++;
				cout << " new num is=" << temp << endl;

				x = temp;
				continue;
			}
		} else
			x = 3 * x + 1;
		cout << x << endl;

		if (x == 1) {
			cout << " we entered the loop! :(" << endl;
			temp++;
			cout << " new num is=" << temp << endl;

			x = temp;
			continue;
		}

	}

	*/


	//---------------------------------------------------------------------------------
					//h.w13 cpp4kids 14#
/*

	int case_num, int_num, num, s_sum;

	int i = 0;
	cin >> case_num;

	while (i < case_num) {
		cin >> int_num;
		int j = 0;
		s_sum = 0;
		while (j < int_num) {
			cin >> num;
			s_sum = s_sum + pow(num, j + 1);
			j++;

		}
		cout << s_sum << endl;
		i++;
	}


*/








	//###################################  <<<<<.17#.>>>>>##############################################
	//---------------------------------------------------------------------------------
					//h.w1 cpp4kids 17#
/*


	int star_cros;
	cin >> star_cros;

	if (star_cros % 2 == 0) //if not odd stop
		return 0;

	for (int i = 0; i < star_cros; i++) {

		for (int j = 0; j <= star_cros; j++) {

			if ((i + 1 == star_cros / 2 + 1) && (j == star_cros / 2)) {

				cout << '*';
				break;
			}
			if (j == i)
				cout << '*';

			else if (i == (star_cros) - (j+1))
				cout << '*';

			else {
				cout << " ";
			}

		}

		cout << endl;
	}
*/


	//---------------------------------------------------------------------------------
					//h.w3 cpp4kids 17#
//took too much time (saw the solution not to much diff but my code didn't work at all "bug")

/*
	for (int i = 1; i <= 200; i++) {

		for (int j = 1; j <= 200; j++) {

			for (int k = 1; k <= 200; k++) {
				int l=i+j-k;

				if(l>=1 && l<=200){
					cout << i << " " << j << " " << k<< " "  << l << endl;
				}






			}
		}
	}

	*/


	//---------------------------------------------------------------------------------
					//h.w5 cpp4kids 17#

	//NOTE: I was supposed to put the answer incrementally not decrementally...
/*
	int max_num, prim_cntr = 0;
	cin >> max_num;

	if (max_num >= 500) //h.w constrain
		return 0;

	for (int i = 1; i <= max_num - 1; ++i) {

		if (max_num % (max_num - i) == 0 && max_num != 3 && max_num != 2) {//max_num !== 3,2 are special cases for my 'ONE' loop solution!!.
			i = 1;

		} else if (max_num % (max_num - i) != 0 || max_num == 2
				|| max_num == 3) {

			if (i == max_num - 2 || max_num == 2 || max_num == 3) { //max_num == 3,2 are special cases for my 'ONE' loop solution!!.
				if (prim_cntr != 0)
					cout << ',';

				cout << max_num;
				prim_cntr++;
				if (max_num == 3) {
					i = 0;
					max_num--;
				}
			}
		}

	}
	*/


	//---------------------------------------------------------------------------------

	//h.w6 cpp4kids 17#

	/*
	int n, a, b, POW1, POW2;
	int temp = 0;
	int sum = 0;
	cin >> n >> a >> b;

// set and store maximum digits
//check sum of digits for each number
//if its true sum+=n;

	if (n == 0)
		return 0;

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= 6; j++) {
			POW1 = pow(10, j + 1);
			POW2 = pow(10, j);
			temp += ((i % POW1) / POW2);

		}
		if (temp <= b && a <=temp ) {
			temp = 0;
			sum += i;
		}
	}


	cout << sum; // solution should work don't know  why its not!
	//i can replace inner for loop with while (nice idea check course solution
*/
	/////////WELL DONE !! got em all "almost"
}

