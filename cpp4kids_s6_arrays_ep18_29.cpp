//============================================================================
// Name        : cpp4kids_s6(arrays)....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice (<3)
// Description : solving cpp4kids H.Ws (arrays) C++, Ansi-style
//============================================================================
//#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	//---------------------------------------------------------------------------------
					//h.w1 cpp4kids 20#
/*

	int mx_nms, mx_occrs;

	cin >> mx_nms;
	int mains_ary[mx_nms];
	for (int i = 0; i < mx_nms; ++i) {
		cin >> mains_ary[i];
	}

	cin >> mx_occrs;
	int occur_ary[mx_occrs];
	for (int i = 0; i < mx_occrs; ++i) {
		cin >> occur_ary[i];
	}

//finish cin all variable and arrays

	for (int i = 0; i < mx_occrs; ++i) {

		for (int j = 0, cntr = 0, temp = 0; j < mx_nms; ++j) {
			if (occur_ary[i] == mains_ary[j]) {
				cntr++;
				temp = j;
			} else if (cntr == 0)
				temp = -1;

			if (j == mx_nms - 1)
				cout << temp << endl;
		}

	}

	*/

	//---------------------------------------------------------------------------------
					//h.w4 cpp4kids 20#
	/*

// 1st solution: i will iterate more than once :) but not with the main array !! XD
// O(n)=n^2 approx

	int mains, scnd_ary[300];

	cin >> mains; //input section
	if (mains < 3)
		return 0;

	 int nms_ary[mains];
	for (int i = 0; i < mains; ++i) {
		cin >> nms_ary[i];
		scnd_ary[i] = nms_ary[i];
	}

//comparing section

	for (int i = 0, temp; i < mains; ++i) {
		for (int j = i + 1; j < mains; ++j) {

			if (scnd_ary[i] >= scnd_ary[j]) {
				temp = scnd_ary[i];
				scnd_ary[i] = scnd_ary[j];
				scnd_ary[j]=temp;
			}
		}
	}
	//output section
		cout << scnd_ary[i]<<" ";
*/








/*
#####################################################
	//2nd solution(faster) : Iterate only once
//O(n)=n approx maybe i make it log(n) later

	int mains, st_lwst = 10000, nd_lwst = 10001, rd_lwst = 10002;

	cin >> mains; //input section
	if (mains < 3)
		return 0;

	int nms_ary[mains];
	for (int i = 0; i < mains; ++i)
		cin >> nms_ary[i];

//comparing section
	for (int i = 0; i < mains; ++i) {

		if (nms_ary[i] < st_lwst) {
			rd_lwst = nd_lwst;
			nd_lwst = st_lwst;
			st_lwst = nms_ary[i];
		}

		if (nms_ary[i] > st_lwst && nms_ary[i] < nd_lwst) {
			rd_lwst = nd_lwst;
			nd_lwst = nms_ary[i];
		}

		if (nms_ary[i] > st_lwst && nms_ary[i] > nd_lwst
				&& nms_ary[i] < rd_lwst) {
			rd_lwst = nms_ary[i];
		}

	}

	//output section
	cout << st_lwst << " " << nd_lwst << " " << rd_lwst;
*/






	//---------------------------------------------------------------------------------
					//h.w7 cpp4kids 20#
	//course solution is 24 lines mine is 40 approx :(
/*
	int mx_nm, freq_ary[770] = { 0 }, freq_copy[770] = { 0 };

	cin >> mx_nm;
	int main_ary[mx_nm];

	for (int i = 0; i < mx_nm; ++i) {
		cin >> main_ary[i];
	}

	for (int i = 0; i < mx_nm; ++i) {

		if (main_ary[i] < 0)
			freq_ary[main_ary[i] * (-1) + 270]++;

		freq_ary[main_ary[i]]++;
//we made negative mains starts after index 270 in freq_ary => e.g.(-1=271)
//this is because we want  to make  negative index BUT we can't so we ciphered it!
	}

	for (int i = 0; i < 770; ++i) {

		freq_copy[i] = freq_ary[i];
//copying  freq_ary to stay safe!	for (int i = 0; i < 770; ++i) {
	}

	for (int i = 0; i < 770; ++i) {
		if (freq_copy[0] <= freq_copy[i + 1])
			freq_copy[0] = freq_copy[i + 1];
	}

	for (int i = 0; i < 770; ++i) {
		if (freq_copy[0] == freq_ary[i]) {
			if (i > 270) {
				cout << i * (-1) + 270;
				continue;
			}
			cout << i;

		}
	}

*/



	//---------------------------------------------------------------------------------
					//h.w10 cpp4kids 20#
	/*
	int mx_nm, sub_dgt, ndx[2]={0}, sub_sum = 0;

	cin >> sub_dgt;
	cin >> mx_nm;
	//int sub_ary[sub_dgt] = { 0 };
	int main_ary[mx_nm];

	for (int i = 0; i < mx_nm; ++i) {
		cin >> main_ary[i];
	}

	for (int i = 0, temp = 0; i < mx_nm; ++i) {

		if (mx_nm - i <= sub_dgt - 1) ///not to take smaller than wanted sub array
			break;

		for (int j = 0; j < sub_dgt; ++j)
			temp += (main_ary[i + j]);

		if (i == 0) {
			sub_sum = temp;
			ndx[0] = 0;
			ndx[1] = sub_dgt-1;

		}

		else if (sub_sum < temp) {
			sub_sum = temp;
			ndx[0] = i;
			ndx[1] = i + (sub_dgt-1);
		}
		temp = 0;
	}

	cout << ndx[0] << ndx[1] << "\t" << sub_sum;
	//try later with one loop. (they claim two ways available but hard)
*/






	//---------------------------------------------------------------------------------
					//h.w13 cpp4kids 20# **//h.w12 is more fun and real day problem
/*
	int mx_ppl, steps;

	cin >> mx_ppl;
	if (mx_ppl > 200)
		return 0;

	int main_ary[mx_ppl];
	cin >> steps;

	for (int i = 0; i < mx_ppl; ++i) {
		 main_ary[i] = -1;
	}

	for (int i = steps - 1, cntr = mx_ppl;; i += (steps - 1)) {

		if (i >= mx_ppl) {
			i -= (mx_ppl+1); //to make it keep looping with same steps
			i += (steps - 1);
		}

		if (main_ary[i] == -1) {
			cntr--;
			main_ary[i] = cntr;
			cout << i + 1 << " ";
			i++;
		}
		else { //to skip the removed ppl to the  next nearest unremoved
			for (int j = i + 1, loops = 0; loops < 2; ++j) {
				if (j >= mx_ppl) {
					loops++;
					j = 0;
				}
				if (main_ary[j] == -1) {
					cntr--;
					main_ary[j] = cntr;
					cout << j + 1 << " ";
					i = j + 1;
				}
			}

		}

		if (cntr == 0)
			break;
	}
	*/
//yaaay u did most of 20# h.ws.(u can go back later to solve h.w9 "recaman's". looks fun).

















	//###################################  <<<<<.23#.>>>>>##############################################

	//---------------------------------------------------------------------------------
			//h.w1 cpp4kids 23#
/*
	// NOTE: maineric value of white space is 0 ==> (int)whitespace = 0
	char main_str[200], is_prfx[200] = { 0 };
	cin >> main_str >> is_prfx;

	int i, cntr;
	for (i = 0, cntr = 0; is_prfx[i] != ' '; ++i) {//another condition i < (int)is_prfx.size()

		if (main_str[i] == is_prfx[i])
			cntr++;
		else
			break;
	}

	if (cntr == i && cntr != 0)
		cout << "YES";
	else
		cout << "NO";

*/



	//---------------------------------------------------------------------------------
					//h.w4 cpp4kids 23#

/*
	char main_str[200] = { 0 }, is_sbseq[200] = { 0 };
	cin >> main_str >> is_sbseq;

	int i, j, cntr, sbseq_size = 0;
	for (i = 0, cntr = 0; main_str[i] != '\0'; ++i) {

		for (j = 0 + cntr; is_sbseq[j] != '\0'; ++j) {

//j=0 + cntr  is condition to skip comparing founded element  again.
//meaning:  element VALUES  can be duplicated but founded exact element again? no!
//e.g.(if element with specific indx [0] was found once then we exclude it. next time we start from indx[1])
// (if is_sbseq[x] == is_sbseq[y] its okay we'ill search for both NO skipping here!)
//but order must not change i.e.(its a SUB-SEQ.!)

			if (main_str[i] == is_sbseq[j]) {
				cntr++;
				break;
			}
		}

	}

// I need to count how many elements in is_sbseq[]:
	for (int var = 0; is_sbseq[var] != '\0'; ++var) {
		sbseq_size++;
	}//or make it string and just ==> sbseq_size = (int) is_sbseq.size();



	if (cntr == sbseq_size)
		cout << "YES";
	else
		cout << "NO";
// (NULL = char'\0'= 0) and maybe equal to whitespace  char' '.
*/

	//---------------------------------------------------------------------------------
					//h.w6 cpp4kids 23#
	//checked it 25/9/2021 suddenly doesn't work but its easy  to remade
/*
	char main_string[200] = { 0 }, grouped_str[200] = { 0 };

	cin >> main_string;

	for (int i = 1; main_string[i] != '\0'; i++) {

		if (i == 1)
			grouped_str[i - 1] = main_string[i - 1];

		int cntr = 0;
		while (main_string[i - 1] == main_string[i]) {

			grouped_str[i + 1] = main_string[i];

			if (cntr == 0)
				grouped_str[i] = main_string[i];

			cntr++;
			i++;
		}

		grouped_str[i] = ' ';
		grouped_str[i + 1] = main_string[i];

	}

	cout<< grouped_str;
*/





	//---------------------------------------------------------------------------------
					//h.w9 cpp4kids 23#
	//course made waay shorter
	/*
//NOTES TO ME!

	// from string to int  use stoi()
	//from int to str use to_string()
	//there is another ways and other functions from c libraries

	char dgt_str[200] = { 0 };
	static int chr_cntr, LSB;

	cin >> dgt_str;	//at least 6 digits

	for (int i = 0; dgt_str[i] != '\0'; ++i) {
		chr_cntr++;
	}

//cout<<"chr_cntr "<<chr_cntr<<endl;
	LSB = 2 * chr_cntr - 2;
//cout<<"lsb "<<LSB<<endl;

	char arng_str[2 * chr_cntr] = { 0 };

	for (int i = chr_cntr - 1, j = 0; i < LSB + 1; ++i, ++j) {

		if (j < chr_cntr - 1)
			arng_str[j] = '0'; //fill zeroes left to the mainber

		arng_str[i] = dgt_str[j]; //copy the mainber to arranged array
	}

//THE important code blocks COMES NOW
//p1: if last 4 digits ='0' just replace with '5'

	static int easy;
	for (int i = LSB; i >= LSB - 3; --i) {

		if (arng_str[i] == '0')
			++easy;
	}

	if (easy == 4) {
		for (int i = LSB; i >= LSB - 3; --i)
			arng_str[i] = '5';
	}

//p2:
	else {
		for (int i = 0, j = 0, finl_add = 0, str2int = 0; i < 4; ++i) {
//cout<<arng_str<<endl;
//cout<<'i'<<i<<endl;

			str2int = int(arng_str[LSB - i]) - 48; //48=int('0')

//cout<<"str2int "<<str2int<<endl;
			finl_add = 5 - (10 - str2int); //if 0 or +ve we use it
//cout<<"finl_add "<<finl_add<<endl;
			//previous line is to find the final value of the current digit that we checking

			if (arng_str[LSB - i] + 5 > '9') { //could also use condition  finl_add >=0

				j = 0;
				while (arng_str[LSB - 1 - i - j] >= '9'
						&& LSB - 1 - i - j >= chr_cntr - 1) {
//cout<<"element value "<<arng_str[LSB-1-i-j]<<endl;
					j++;
				}
//cout<<"element value "<<arng_str[LSB-1-i-j]<<endl;
				cout<<'j'<<j<<endl;

				if ((LSB - 1) - i - j >= chr_cntr - 1) {
					//I could optimize it later to merge this and else block in one block

					arng_str[LSB - 1 - i - j]++;
//cout<<arng_str<<endl;

					for (int k = LSB - i; k > LSB - 1 - i - j; --k) {
						arng_str[k] = '0';
					}
//cout<<arng_str<<endl;
					if ((j > 2 && i == 0) || (i == 1 && j > 1)
							|| (i == 2 && j > 0)) {

						for (int k = LSB - i; k >= LSB - 3; --k)
							arng_str[k] = '5';
//cout<<arng_str<<endl;

						arng_str[LSB - i] = '0' + finl_add;
//cout<<arng_str<<endl;
						//could finl_add be negative and we already reached this line!? => ans=NO :D!
						break;
					}
					else {

						for (int k = LSB - i,cntr=-1; k > LSB - 1 - i - j; --k){
							arng_str[k] = '5';
							cntr++;
							j=cntr;
						}
//cout<<arng_str<<endl;

						arng_str[LSB - i] = '0' + finl_add;
//cout<<arng_str<<endl;

						i += j;
						continue;
					}

				}

				else { //this runs if the reason while loop -line 467- stopped is cuz we reached MSB


					arng_str[chr_cntr - 2] = '1';

					for (int k = LSB - i; k >= chr_cntr - 1; --k) {

						if (k == LSB - i)
							arng_str[k] = '0' + finl_add;

						else if (k < LSB - i && k >= LSB - 3)
							arng_str[k] = '5';

						else if (k < LSB - 3)
							arng_str[k] = '0';

					}
					break; //to go to final output directly
				}

			} else {
				arng_str[LSB - i] += 5;
			}
		}
	}

//final output //don't forget to skip zeroes at left!.

	for (int i = 0, skp = 1; i < 2 * chr_cntr; ++i) {

		if (skp == 1 && arng_str[i] == '0')
			continue;

		else {
			skp = 0;
			cout << arng_str[i];
		}
	}
*/


	//---------------------------------------------------------------------------------
					//h.w10 cpp4kids 23# (1ST PPROGRAM!)

//maybe in a separated source(if many lines )
//then we call it here as  a func :D? ""maybe"".

















	//###################################  <<<<<.26#.>>>>>##############################################
	//###################################  <<<<<.2D ARRAY.>>>>>##############################################

	//---------------------------------------------------------------------------------
					//تمرين تسخين h.w0 cpp4kids 25#
	//or use direction array di[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
	//                       dj[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
	//above means ==> direction[8]={ d, r,  u,  l, ul, dr, ur, dl };
//NOTE: 2d_ary[row][colm]
/*
	int find_nighbr[3][3] = { { 1, 2, 3 }, { 4, 0, 5 }, { 6, 7, 8 } };

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {

			if (find_nighbr[i][j] == find_nighbr[1][1])
				continue;
			cout << find_nighbr[i][j] << endl;

		}

	}

*/

	//---------------------------------------------------------------------------------
					//h.w3 cpp4kids 26#
	//can use direc arra also but 3rd 8 steps loop will be there insted of 8 if statement
/*
	int a, b;
	cin >> a >> b;
	int mat1[a][b];

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			cin >> mat1[i][j];
		}
	}

	for (int i = 0; i < a; ++i) { //flaten the array and bam! u need one loop only :D
		for (int j = 0; j < b; ++j) {

			if (i - 1 >= 0) {					//up neigh.
				if (mat1[i - 1][j] >= mat1[i][j])
					continue;
			}
			if (j + 1 < b) {					//right neigh.
				if (mat1[i][j + 1] >= mat1[i][j])
					continue;
			}
			if (i + 1 < a) {					//down neigh.
				if (mat1[i + 1][j] >= mat1[i][j])
					continue;
			}
			if (j - 1 >= 0) { //left neigh.
				if (mat1[i][j - 1] >= mat1[i][j])
					continue;
			}
			if (i - 1 >= 0 && j - 1 >= 0) {					//up left neigh.
				if (mat1[i - 1][j - 1] >= mat1[i][j])
					continue;
			}
			if (i - 1 >= 0 && j + 1 < b) { //up right neigh.
				if (mat1[i - 1][j + 1] >= mat1[i][j])
					continue;

			}
			if (i + 1 < a && j - 1 >= 0) { //down left neigh.
				if (mat1[i + 1][j - 1] >= mat1[i][j])
					continue;
			}
			if (i + 1 < a && j + 1 < b) { //down right neigh.
				if (mat1[i + 1][j + 1] >= mat1[i][j])
					continue;
			}

			cout << i << " " << j << endl;
		}

	}

*/



	//---------------------------------------------------------------------------------
					//h.w4 cpp4kids 26#

/*
	//I can run the 2 nested loops  by printing and  checking every 2 rounds (x plays o plays = 2 rounds)

	//Initializing game
	int size, r, c, round_cntr = 0;
	bool plyr_swtch = false;
	static int crs_winX, hrz_winX, vrtcl_winX, ant_crs_winX;
	static int crs_winO, hrz_winO, vrtcl_winO, ant_crs_winO;

	cin >> size;
	if (size < 3 || size > 9)
		return (0);

	char game_tbl[size][size];
	cout << "Round 0" << endl;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {

			game_tbl[i][j] = '*';
			cout << game_tbl[i][j] << " ";
		}
		cout << endl;
	}

	cout << "#player 1 will use 'x'" << endl << "#player 2 will use 'o'"
			<< endl;


	//game starts
	for (;;) {

		cout << endl << "player " << 1 + plyr_swtch << ':'<< " choose location to play (x,y): ";
		cin >> r >> c;

//WARNING: added next  if condition  without chk
if(game_tbl[r][c]!='*' || r < 0 ||c < 0 || r >= size ||c >= size){
cout<< "Invalid. Try again \n";
continue;
}

		if (plyr_swtch == false)
			game_tbl[r][c] = 'x';
		else
			game_tbl[r][c] = 'o';



		for (int i = 0; i < size; ++i) {

			for (int j = 0; j < size; ++j) {

				cout << game_tbl[i][j] << " ";


				if (game_tbl[i][j] != '*') {
					if (game_tbl[i][j] == 'x')
						hrz_winX++;
					else
					hrz_winO++;
				}

				if (game_tbl[j][i] != '*') {

					if (game_tbl[j][i] == 'x')
						vrtcl_winX++;
					else
					vrtcl_winO++;
				}
			}

			if (game_tbl[i][i] != '*') {
				if (game_tbl[i][i] == 'x')
					crs_winX++;
				else
				crs_winO++;
			}
				if (game_tbl[i][size - 1 - i] != '*') {
					if (game_tbl[i][size - 1 - i] == 'x')
						ant_crs_winX++;
					else
					ant_crs_winO++;
				}

			if (hrz_winX == size || vrtcl_winX == size ||hrz_winO == size || vrtcl_winO == size) {
				cout << "player " << 1 + plyr_swtch << " has won!"<<endl;

				for (int i = 0; i < size; ++i) {// print final wining move
					for (int j = 0; j < size; ++j) {
						cout << game_tbl[i][j] << " ";
					}
					cout << endl;
				}

				return (0);
			}

			hrz_winX = 0, hrz_winO = 0;
			vrtcl_winX = 0, vrtcl_winO = 0;
			cout << endl;
		}
		round_cntr++;


		if (crs_winX == size ||ant_crs_winX == size || crs_winO == size ||ant_crs_winO == size) {
			cout << "player " << 1 + plyr_swtch << " has won!"<<endl;
			break;

		}else if (round_cntr >= size * size) {
			cout << "DROW!";
			break;
		}

		crs_winX = 0, crs_winO = 0;
		ant_crs_winX = 0, ant_crs_winO = 0;

		plyr_swtch = !plyr_swtch;
	}//to next round


	for (int i = 0; i < size; ++i) {// print final wining move
		for (int j = 0; j < size; ++j) {
			cout << game_tbl[i][j] << " ";
		}
		cout << endl;
	}

	*/




	//---------------------------------------------------------------------------------
					//h.w6 cpp4kids 26#
	/*
int n,m;
cin>>n>>m;
 int mat1[n][m],mat2[m][n];

for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
		cin>>mat1[i][j];
	}
}

for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
mat2[j][i]=mat1[i][j];
	}
}
//end of solution


//this part to check only
for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
		cout<<mat1[i][j];
	}
	cout<<endl;
}

cout<<"\n \n";

for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
		cout<<mat2[i][j];
	}
	cout<<endl;
}

*/

	//---------------------------------------------------------------------------------
						//h.w8 cpp4kids 26#
//I hate who says 1 is not prime number , ***%$!@* change PRIME to any other word!
	//done one try + less lines + I guess not complex than course solution :D not the only one though!

	/*
	int main_ary[200][200] = { 0 };
	int n, m;

	int q;
	int i2, j2, r, c;

	cin >> n >> m;
	int half_value = 0, prime_cntr = 0;
	bool no_prime = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> main_ary[i][j];

	cin >> q;
	for (int i = 0; i < q; ++i) {

		cin >> i2 >> j2 >> r >> c;

		for (int i = i2; i < i2 + r; ++i) {
			for (int j = j2; j < j2 + c; ++j) {	//sub_array[0][0] "1st element" == main_ary[i][j]);

				half_value = main_ary[i][j] / 2;

				for (int k = 2; k <= half_value; ++k) {

					if (main_ary[i][j] % k == 0) {
						no_prime = 1;
						break;
					}

				}

				if (no_prime == 0)
					prime_cntr++;

			}
		}
		cout << prime_cntr << endl;
	}

	return (0);
}
 */

//hurray finished ur s6 homeworks !!! :D (actually ppproject missing but u will do similar later on)

