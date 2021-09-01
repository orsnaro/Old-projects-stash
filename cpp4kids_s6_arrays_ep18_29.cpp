//============================================================================
// Name        : cpp4kids_s6(arrays)....
// Author      : Omar.R.S
// Version     :
// Copyright   : Your copyright notice (<3)
// Description : solving cpp4kids H.Ws (arrays) C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	//---------------------------------------------------------------------------------
					//h.w1 cpp4kids 20#
/*

	int mx_nms, mx_occrs;

	cin >> mx_nms;
	int nums_ary[mx_nms];
	for (int i = 0; i < mx_nms; ++i) {
		cin >> nums_ary[i];
	}

	cin >> mx_occrs;
	int occur_ary[mx_occrs];
	for (int i = 0; i < mx_occrs; ++i) {
		cin >> occur_ary[i];
	}

//finish cin all variable and arrays

	for (int i = 0; i < mx_occrs; ++i) {

		for (int j = 0, cntr = 0, temp = 0; j < mx_nms; ++j) {
			if (occur_ary[i] == nums_ary[j]) {
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

	int nums, scnd_ary[300];

	cin >> nums; //input section
	if (nums < 3)
		return 0;

	 int nms_ary[nums];
	for (int i = 0; i < nums; ++i) {
		cin >> nms_ary[i];
		scnd_ary[i] = nms_ary[i];
	}


//comparing section

	for (int i = 0, temp; i < nums; ++i) {
		for (int j = i + 1; j < nums; ++j) {

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

	int nums, st_lwst = 10000, nd_lwst = 10001, rd_lwst = 10002;

	cin >> nums; //input section
	if (nums < 3)
		return 0;

	int nms_ary[nums];
	for (int i = 0; i < nums; ++i)
		cin >> nms_ary[i];

//comparing section
	for (int i = 0; i < nums; ++i) {

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
//we made negative nums starts after index 270 in freq_ary => e.g.(-1=271)
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
					//h.w8 cpp4kids 23#















	return 0;
}
