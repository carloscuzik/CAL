#ifndef RSA_H
#define RSA_H

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
#include "BigIntegerLibrary.hh"

typedef struct ${
	BigInteger x;	
	BigInteger y;
	BigInteger mdc;	
}Trio;

class RSA{
private:
	BigInteger p;
	BigInteger q;
	BigInteger n;
	BigInteger alpha;
	int e;
	BigInteger d;
public:
	RSA();
	~RSA();
	void generate_keys(BigInteger p, BigInteger q);
	int choose_e();
	BigInteger choose_d(BigInteger e, BigInteger n);
	//Do this functions to use later
	int choose_a_small_prime_number();
	BigInteger probable_prime_number(int bits);
	bool is_prime_number(BigInteger number);
	Trio extended_euclid(BigInteger a, BigInteger b);
	BigInteger modular_reverse(BigInteger a, BigInteger b);
	// Trio gcdExt()
	//end
	BigInteger mdc(BigInteger a, BigInteger b);
	BigInteger get_p();
	BigInteger get_q();
	BigInteger get_n();
	int get_e();
	BigInteger get_d();
	void encrypt(std::string input, std::string output, BigInteger n, BigInteger e);
	std::vector<std::string> split_message(std::string message, int size_split);
	std::vector<std::string> block_message_2_bin_number(std::vector<std::string> block_message);
	std::string string_2_bin_number(std::string parcer_message);
	std::string dec_number_2_bin_number(BigInteger dec_number);
	int length_bin_number(BigInteger dec_number);
	BigInteger pow_BI(BigInteger n, BigInteger a);
	BigInteger pow_BI_Mod(BigInteger n, BigInteger a, BigInteger m);
	std::string zero_complete(std::string atual_bin_number, int size_last);
	std::vector<BigInteger> block_bin_number_2_dec_number(std::vector<std::string> code_bin_number);
	BigInteger bin_number_2_dec_number(std::string bin_number);
	std::vector<BigInteger> block_dec_number_2_encrypt_data(std::vector<BigInteger> code_dec_number, BigInteger n, BigInteger e);
	BigInteger dec_number_2_encrypt_data(BigInteger dec_number, BigInteger n, BigInteger e);
	BigInteger mod_BI(BigInteger n, BigInteger a);
	std::string read_file(std::string file_name);
	void write_cipher_in_file(std::string file_name, std::vector<BigInteger> block_encrypt_data);
	void write_message_decipher_in_file(std::string file_name, std::string message_decrypt);
	std::vector<BigInteger> read_file_cipher(std::string file_name);
	void decrypt(std::string input, std::string output, BigInteger n, BigInteger d);
	std::vector<std::string> block_dec_number_2_bin_number(std::vector<BigInteger> code_dec_number );
	std::vector<std::string> block_bin_number_2_parcer_message(std::vector<std::string> code_bin_number);
	std::string bin_number_2_parcer_message(std::string bin_number);
	std::string block_message_2_single_message(std::vector<std::string> block_message);
	BigInteger brute_force_attack(BigInteger n, BigInteger e);
};

#endif /* RSA_H */