#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <sys/time.h>
#include <fstream>

//bibliotecas locais
#include "rsa.h"
#include "BigIntegerLibrary.hh"

BigInteger pow_donkey(BigInteger n, BigInteger a);
void print_time(clock_t t_total);

using namespace std;

int main(){
	clock_t t_start,t_end;
	RSA *rsa = new RSA();
	int type;
	BigInteger par_01;
	BigInteger par_02;
	if(arcg!=4){
		printf("Midding argument\n");
		return EXIT_FAILURE;
	}else{
		type = atoi(argv[1]);
		par_01 = stringToBigInteger(std::string(argv[2]));
		par_02 = stringToBigInteger(std::string(argv[3]));
	}
	switch(type){
		case 0:
			t_start = clock();
			rsa->encrypt("input","output",par_01,par_02);
			t_end = clock();
			print_time(t_end - t_start);
			break;
		case 1:
			t_start = clock();
			rsa->decrypt("input","output",par_01,par_02);
			t_end = clock();
			print_time(t_end - t_start);
			break;
		case 2:
			rsa->genarate_keys(521,383);
			break;
		case 6:
			BigInteger d_discovered = rsa->brute_force_attack(par_01,par_02);
			break;
		default:
			break;
	}
	return 0;
}

void print_time(clock_t t_total){
	long double time_a = t_total/(CLOCKS_PER_SEC/1.0);
	int hours = time_a/3600;
	time_a -= hours*3600;
	int minutes = time_a/60;
	tima_a -= minutes*60;
	int seconds = (int)tima_a;
	time_a -= seconds;
	double milliseconds = time_a;
	cout << "----- TOTAL TIME -----" << endl;
	cout << hours << ":" << minutes << ":" << seconds << ":" << milliseconds << endl;
}