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
#include "BigIntegerLibrary.h"

BigInteger pow_donkey(BigInteger n, BigInteger a);
void print_time(clock_t t_total);

using namespace std;

int main(int argc, const char *argv[]){
	clock_t t_start,t_end;
	RSA *rsa = new RSA();
	int type;
	BigInteger par_01;
	BigInteger par_02;
	if(argc!=4){
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
			rsa->decrypt("output","input",par_01,par_02);
			t_end = clock();
			print_time(t_end - t_start);
			break;
		case 2:
			rsa->generate_keys(par_01,par_02);
			cout << "p: " << rsa->get_p() << endl;
			cout << "q: " << rsa->get_q() << endl;
			cout << "n: " << rsa->get_n() << endl;
			cout << "e: " << rsa->get_e() << endl;
			cout << "d: " << rsa->get_d() << endl;
			break;
		case 5:
			std::cout << rsa->pow_BI(2,4423) - 1 << std::endl;
			std::cout << rsa->pow_BI(2,9689) - 1 << std::endl;
			break;
		case 6:
			t_start = clock();
			BigInteger d_discovered = rsa->brute_force_attack(par_01,par_02);
			rsa->decrypt("output","input",par_01,d_discovered);
			t_end = clock();
			print_time(t_end - t_start);
			break;
	}
	return 0;
}

void print_time(clock_t t_total){
	long double time_a = t_total/(CLOCKS_PER_SEC/1.0);
	int hours = time_a/3600;
	time_a -= hours*3600;
	int minutes = time_a/60;
	time_a -= minutes*60;
	int seconds = (int)time_a;
	time_a -= seconds;
	double milliseconds = time_a*1000;
	cout << "----- TOTAL TIME -----" << endl;
	cout << hours << ":" << minutes << ":" << seconds << ":" << milliseconds << endl;
}