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
void run_test();

using namespace std;

int main(int argc, const char *argv[]){
	srand(time(NULL));
	clock_t t_start,t_end;
	RSA *rsa = new RSA();
	Trio t;
	int type;
	BigInteger par_01;
	BigInteger par_02;
	if(argc!=4){
		printf("Midding argument\n");
		printf("         Descrição        -      Paramentros\n");
		printf("2 - Para Gerar as Chaves ... (./ hocus_pocus 3 número de bits 0)\n");
		printf("0 - Para Criptgrafia     ... (./ hocus_pocus 3 n e)\n");
		printf("1 - Para Decriptar       ... (./ hocus_pocus 3 n d)\n");
		printf("6 - Para Força Bruta     ... (./ hocus_pocus 3 n e)\n");
		printf("3 - Para Rodar os testes ... (./ hocus_pocus 3 0 0)\n");
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
			if(par_02 == 0)
				rsa->generate_keys(par_01.toInt());
			else{
				rsa->generate_keys(par_01,par_02);
			}
			cout << "p: " << rsa->get_p() << endl;
			cout << "q: " << rsa->get_q() << endl;
			cout << "n: " << rsa->get_n() << endl;
			cout << "e: " << rsa->get_e() << endl;
			cout << "d: " << rsa->get_d() << endl;
			break;
		case 3:
			run_test();
			break;
		case 4: 
			// cout << rsa->sqrt(239812014798221) << endl;
			// cout << rsa->next_prime(7) << endl;
			// cout << rsa->is_prime_number(par_01,512) << endl;
			break;
		case 5:
			// std::cout << rsa->pow_BI(2,4423) - 1 << std::endl;
			// std::cout << rsa->pow_BI(2,9689) - 1 << std::endl;
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
	// printf("%llf\n",time_a);
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

#define NUM_AMOSTRAS 1
double media(double vetor[]);

void run_test(){
	int i,j;
	clock_t t_start,t_end;
	double crip[NUM_AMOSTRAS];
	double decr[NUM_AMOSTRAS];
	double bfat[NUM_AMOSTRAS];
	RSA *rsa = new RSA();
	for(i=32;i<100;i++){
		rsa->generate_keys(i);
		for(j=0;j<NUM_AMOSTRAS;j++){
			//Criptografia
			t_start = clock();
			rsa->encrypt("input","output",rsa->get_n(),rsa->get_e());
			t_end = clock();
			crip[j] = (double) (t_end-t_start)/(CLOCKS_PER_SEC/1.0);
			
			//Decriptografia
			t_start = clock();
			rsa->decrypt("output","input",rsa->get_n(),rsa->get_d());
			t_end = clock();
			decr[j] = (double) (t_end-t_start)/(CLOCKS_PER_SEC/1.0);

			//Força Bruta
			t_start = clock();
			BigInteger d_discovered = rsa->brute_force_attack(rsa->get_n(),rsa->get_e());
			rsa->decrypt("output","input",rsa->get_n(),d_discovered);
			t_end = clock();
			bfat[j] = (double) (t_end-t_start)/(CLOCKS_PER_SEC/1.0);
		}
		printf("%lf\n",media(crip));
		printf("%lf\n",media(decr));
		printf("%lf\n",media(bfat));
	}
}

double media(double vetor[]){
	double soma = 0;
	int i;
	for(i=0;i<NUM_AMOSTRAS;i++){
		soma += vetor[i];
	}
	return soma/NUM_AMOSTRAS;
}