//============================================================================
// Name        : cpp4kids_s3....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice
// Description : solving cpp4kids H.W (variable in\out) C++, Ansi-style
//============================================================================



#include <iostream>
using namespace std;

int main() {

	//---------------------------------------------------------------------------------
	//h.w2 cpp4kids 6#
	//cout<<"*\n*  *\n*  *  *\n*  *  *  *\n*  *  *  *  *"<<endl;






	//---------------------------------------------------------------------------------
	//**h.w1 cpp4kids 7&8#**

	/*
	 int x, y;
	 cout << "\nenter your two integer numbers\n";
	 cin >> x >> y;
	 cout << endl << "x+y="<<x+y<<""<< endl;
	 cout << x << '-' << y << '=' << x - y << endl;
	 cout << x << '*' << y << '=' << x * y << endl;
	 cout << x << '/' << y << '=' << x / y << endl;
	 */




//---------------------------------------------------------------------------------
	/*//h.w2 cpp4kids 7&8#**
	 string name;
	 float grade;

	 cout << "\n\tplease enter your first name:\n";
	 cin >> name;
	 cout << "\nplease input your grade precisely:\n";
	 cin >> grade;

	 cout << "\n--------------------------------------------------\n";
	 cout << "s.name:\t" << name << endl << "s.grade:\t" << grade << endl;
	 */




	//---------------------------------------------------------------------------------
	//h.w3 cpp4kids 7&8# (IMP. TO CHECK COURSE SOLUTION!!!cuz mine seems bit long)
	/*
	int n1, n2, n3, n4, n5, n6, n7, n8;
	bool activ_odd; //set all even  places value to ZERO  when activated ==>"true"

	cout << "\nenter 8 numbers\n";
	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8;

	activ_odd = true;

	cout << "\n odd sum="
			<< (n1 * activ_odd) + (n2 * (!activ_odd)) + (n3 * activ_odd) + (n4 * (!activ_odd))
					+ (n5 * activ_odd) + (n6 * (!activ_odd)) + (n7 * activ_odd) + (n8 * (!activ_odd))
			<< endl;

	activ_odd = false;
	cout << "\n even sum="
			<< (n1 * activ_odd) + (n2 * (!activ_odd)) + (n3 * activ_odd) + (n4 * (!activ_odd))
					+ (n5 * activ_odd) + (n6 * (!activ_odd)) + (n7 * activ_odd) + (n8 * (!activ_odd))
			<< endl;

			*the course solution
			* have multiple cin statements
			* but the 2 formulas used  there is simpler than my one formula used for even and odd sum
*/






	//---------------------------------------------------------------------------------
	//h.w6 cpp4kids 7&8#

	/*
	 int x = 1, y = 2, temp;
	 cout << "x=" << x << "\ny=" << y << "\n";
	 temp = x;
	 x = y;
	 y = temp;

	 cout << "\n\n\n"<<"x=" << x << "\ny=" << y;

*/



	//---------------------------------------------------------------------------------
	//h.w7 cpp4kids 7&8#

	/*
	int x = 15, y = 51, z = 1, temp;

	cout << x << "\t" << y << "\t" << z << endl;
	temp = x;
	x = y;
	y = temp;
	y = z;
	z = temp;

	cout << x << "\t" << y << "\t" << z << endl;

*/





	//---------------------------------------------------------------------------------
	//h.w8 cpp4kids 7&8# (i'm allowed to use more than 2 variables but "only" to read to integers)

/*


	 int A,B;
	 bool C;

	 cout<<"enter \"A\" value:\n";
	 cin>>A;

	 cout<<"\nplease choose either 1 or -1 for \"B\"\n";
	 cin>>B;

	 C=B+1;

	 cout<<((2*A+1)*(!C))+(A*A*C);


*my solution is way simpler and shorter if we remove unimportant "cout" statements i.e.(126,129)
*/

	//---------------------------------------------------------------------------------
		//h.w9 cpp4kids 7&8#

/*
int n;

cout<<"choose any number! :D";
cin>>n;

cout<<(n/2.0)*(1+n); // 2.0 to so important, it makes "n/2" answer to be floating type

*same formula but diff explanation (still arithmatic seq. field)

*/

/////////WELL DONE !! got em all ,don't cilibrate much its only 3rd session (second actual session)/////////


	return 0;
}

