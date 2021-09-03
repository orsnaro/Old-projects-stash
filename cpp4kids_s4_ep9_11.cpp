//============================================================================
// Name        : cpp4kids_s4....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice
// Description : solving cpp4kids H.W (if conditions) C++, Ansi-style
//============================================================================





#include <iostream>
using namespace std;

int main() {

	//----------------------------------10#-----------------------------------------------

	//h.w1 cpp4kids 10#
	//on notebook

	//---------------------------------------------------------------------------------
	//h.w2 cpp4kids 10#
	/*
	 int x,y,z,w,h;
	 cin>>x>>y>>z>>w>>h;
	 cout<<" a) average="<<(double)(x+y+z+w+h)/5<<"";
	 cout<<" b) 1st 3 digit sum / last 2 digit sum =      \n "<<(x+y+z)/(w+h)<<"";
	 cout<<" c) ="<<((x+y+z)/3 )/((w+h)/2)   <<"";
	 */
//* the relation ==> c=2/3b
//*can't find  clear usefull relation between 'a' and 'c'






//---------------------------------------------------------------------------------
	//h.w3 cpp4kids 10#
	/*
	 int a;
	 cin>>a;
	 cout<<((a%10))+((a%100)/10)+((a%1000)/100);

	 */







	//---------------------------------------------------------------------------------
	//h.w4 cpp4kids 10#
	/*
	 int a;
	 cin>>a;
	 cout<< (a%10000)/1000;
	 */






	//---------------------------------------------------------------------------------
	//h.w5  cpp4kids 10#
	/*
	int a, b;

	cin >> a >> b;
	cout << (a % b) / (float) b;
*/



	//---------------------------------------------------------------------------------
			//h.w6 cpp4kids 10#
	/*
	 float a, b;
	 int c;

	 cin >>a >> b;
	 c = a / b;
	 cout << (a/b-c)*b;
	 */





	//---------------------------------------------------------------------------------
			//h.w7 cpp4kids 10#

	/*
	int a;
	bool active;

	cin >> a;

	active = a % 2;

	cout <<  (!active) * 100 + (active) * 7;
*/









	//---------------------------------------------------------------------------------
				//h.w8 cpp4kids 10#

	/*
	 int age_days;

	cin >> age_days;
	cout << age_days / 360 << "\t" << (age_days % 360) / 30 << "\t"
			<< (age_days % 360) - ((age_days % 360) / 30) * 30;
*/


/**************************************************************************11#***************************************************************************************************************************************************/

					//h.w1 cpp4kids 11#
	/*
	  int a, b;
		cin >> a >> b;

		if ((a % 2 != 0) && (b % 2 != 0))
			cout << a * b;

		else if ((a % 2 == 0) && (b % 2 == 0))
			cout << a / b;

		else if ((a % 2 != 0) && (b % 2 == 0))
			cout << a + b;

		else
			cout << a - b;
*/


	//---------------------------------------------------------------------------------
					//h.w2 cpp4kids 11#
/*
int a, b, c;

	cin >> a >> b >> c;

	if (a <= b && a <= c && b <= c)
		cout << a << b << c;

	else if (a <= b && a <= c && b > c)
		cout << a << c << b;

	else if (a <= b && a > c)
		cout << c << a << b;

	else if (a > b && a <= c)
		cout << b << a << c;

	else if (a > b && a > c && b > c)
		cout << c << b << a;

	else
		cout << b << c << a;


	*/








	//---------------------------------------------------------------------------------
					//h.w3 cpp4kids 11#

	/*
	int a, b, c;

	cin >> a >> b >> c;

	if(a >= 100 && b >= 100 && c >= 100)
		cout << -1;
	else if (a >= 100 && b >= 100)
		cout << c;
	else if (a >= 100 && c >= 100)
		cout << b;
	else if (b >= 100 && c >= 100)
		cout << a;

	else if (a >= 100) {
		if (b >= c)
			cout << b;
		else
			cout << c;
	}

	else if (b >= 100) {
		if (a >= c)
			cout << a;
		else
			cout << c;
	}

	else if (c >= 100) {
		if (a >= b)
			cout << a;
		else
			cout << b;
	}

	else{

		if(a>=b && a>=c)
			cout<<a;
		else if (b>=a && b>=c)
			cout<<b;
		else
			cout<<c;
	}

//maybe we can make shorter but more complicated solution using  bool variable as activation tool
	*/









	//---------------------------------------------------------------------------------
						//h.w4 cpp4kids 11#
/*
int a, b, c, d, e, x, smlr_count;

	smlr_count = 5;
	cin >> x >> a >> b >> c >> d >> e;

	if (a > x)
		smlr_count--;
	if (b > x)
		smlr_count--;
	if (c > x)
		smlr_count--;
	if (d > x)
		smlr_count--;
	if (e > x)
		smlr_count--;

 cout << smlr_count << "\t"<<5 - smlr_count<<"";

*/








	//---------------------------------------------------------------------------------
							//h.w5 cpp4kids 11#
/*
	int num,max;

	cin >> num;
	max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cin >> num;
	if (num > max)
		max = num;

	cout<<max;
*/







	//---------------------------------------------------------------------------------
							//h.w6 cpp4kids 11#  (no loops ....... YET! :D)

	/*
	int N, x, max = 0, i = 0;

	cin >> N;

	if (N == i || N < 2 || N > 10)
		cout << "ERROR ( 'N' between 2~10)";

	else
		cin >> x;
	i++;
	if (x > max) {
		max = x;
		cin >> x;
		i++;
	}

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0; // "return 0;" just fancy to stop code auto
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;

	if (N == i || N < 2 || N > 10) {
		cout << max;
		return 0;
	}
	cin >> x;
	i++;
	if (x > max)
		max = x;
	cout << max;
*/







	//---------------------------------------------------------------------------------
					//h.w7 cpp4kids 11#
/*
int x,s1,e1,s2,e2,s3,e3,cntr=0;
cin>>x>>s1>>e1>>s2>>e2>>s3>>e3;

if(x>=s1 && x<=e1)
	cntr++;

if(x>=s2 && x<=e2)
	cntr++;

if(x>=s3 && x<=e3)
	cntr++;

cout<<cntr;

*/








	//---------------------------------------------------------------------------------
					//h.w8 cpp4kids 11#
	/*
	int s1, e1, s2, e2;
	cin >> s1 >> e1 >> s2 >> e2;

	if (s1 >= s2 && s1 <= e2 && e2 >= s1 && e2 <= e1 )
		cout << s1 << "\t" << e2;
	else if (s2 >= s1 && s2 <= e1 && e1 >= s2 && e1 <= e2)
		cout << s2 << "\t" << e1;
	else if (s1 >= s2 && s1 < e2 && e1 > s2 && e1 <= e2)
		cout << s1 << "\t" << e1;
	else if (s2 >= s1 && s2 < e1 && e2 > s1 && e2 <= e1)
		cout << s2 << "\t" << e2;
	else
		cout << -1;
*/
//done s4 homeworks !!!!!!!!!!!
	return 0;

}

