#include "rsa.h"

#define SIZE_BLOCK 4

RSA::RSA(){
	//
}

void RSA::generate_keys(BigInteger p, BigInteger q){
	this->p = p;
	this->q = q;
	this->n = p*q;
	this->alpha = (p-1)*(q-1);
	this->e = choose_e();
	this->d = choose_d(this->e,this->alpha);
}

void RSA::generate_keys(int bits){
	this->p = choose_a_prime_number(bits);
	this->q = choose_a_prime_number(bits);
	this->n = this->p*this->q;
	this->alpha = (this->p-1)*(this->q-1);
	this->e = choose_e();
	this->d = choose_d(this->e,this->alpha);
}

int RSA::choose_e(){
	return choose_a_small_prime_number();
}

int RSA::choose_a_small_prime_number(){
	int i, j;
    int valorMaximo = 100000;
 	std::vector<int> vetor;
 	std::vector<int> primes;
 	vetor.push_back(1);
 	vetor.push_back(1);
    for (i=2; i<=valorMaximo; i++){
        vetor.push_back(i);
    }
    for (i=2; i<=valorMaximo; i++) {
        if (vetor[i]==i) {
        	primes.push_back(i);
            for (j=i+i; j<=valorMaximo; j+=i) {
                vetor[j]=0;
            }
        }
    }
    
    // std::cout << primes[rand() % primes.size()] << std::endl;
    // std::cout << primes[0] << std::endl;
    // std::cout << primes[1] << std::endl;
    // std::cout << primes[2] << std::endl;
    // std::cout << primes[10] << std::endl;
    return primes[rand() % primes.size()];
	// return 9151;
	// return 227;
}

BigInteger RSA::choose_a_prime_number(int bits){
	BigInteger prime_number = probable_prime_number(bits);
	while(!is_prime_number(prime_number,100)){
		prime_number = probable_prime_number(bits);
	}
	return prime_number;
}

BigInteger RSA::probable_prime_number(int bits){
	BigInteger prime_number = (mod_BI(rand(), pow_BI(2,bits-1)+1)) + pow_BI(2,bits);
	if(mod_BI(prime_number,2)==0){
		prime_number--;
	}
	return prime_number;
}

bool RSA::is_prime_number(BigInteger number, int interations){
	if(number <= 3){
		return true;
	}
	if(mod_BI(number,2)==0){
		std::cout << " par " << std::endl;
		return false;
	}
	int s = 0;
	BigInteger d = number - 1;
	while(mod_BI(d,2)==0){
		s++;
		d = d/2;
	}
	int i;
	// BigInteger aux;
	for(i = 0; i < interations; i++) {
		// aux = rand();
		// std::cout << "aux: " << aux << std::endl;
		BigInteger a = (mod_BI(rand(), (number - 3))) + 2;
		// std::cout << "a: " << a << std::endl;
		BigInteger x = pow_BI_Mod(a, d, number);
		if(x == 1 || x == number - 1){
			continue;
		}
		int r = 1;
		for(r = 1; r < s; r++) {
			x = pow_BI_Mod(x, 2, number);
			if(x == 1){
				return false;
			}
			if(x == number - 1){
				break;
			}
		}
		if(r == s){
			return false;
		}
	}
	return true;
}

BigInteger RSA::choose_d(BigInteger e, BigInteger n){
	return modular_reverse(e,n);
}

BigInteger RSA::modular_reverse(BigInteger a, BigInteger b){
	Trio t = extended_euclid(a,b);
	return mod_BI(t.x,b);
}

Trio RSA::extended_euclid(BigInteger a, BigInteger b){
	Trio t;
	if(a<b){
		BigInteger aux = a;
		a = b;
		b = aux;
	}
	
	BigInteger m1 = 1;
	BigInteger m2 = 0;
	BigInteger n1 = 0;
	BigInteger n2 = 1;
	BigInteger res = 0;
	BigInteger quo = 0;
	
	while(b!=0){
		res = mod_BI(a,b);
		quo = a / b;
		a = b;
		b = res;
		if(b==0){
			break;
		}
		t.y = m1-m2*quo;
		t.x = n1-n2*quo;
		m1 = m2;
		m2 = t.y;
		n1 = n2;
		n2 = t.x;
	}
	t.mdc = a;
	return t;
}

BigInteger RSA::mdc(BigInteger a, BigInteger b){
	if(b==0)
		return a;
	else
		return mdc(b,mod_BI(a,b));
}

BigInteger RSA::get_p(){
	return this->p;
}
BigInteger RSA::get_q(){
	return this->q;
}
BigInteger RSA::get_n(){
	return this->n;
}
int RSA::get_e(){
	return this->e;
}
BigInteger RSA::get_d(){
	return this->d;
}

void RSA::encrypt(std::string input, std::string output, BigInteger n, BigInteger e){
	// int tamanho = length_bin_number(n)/8;
	int tamanho = SIZE_BLOCK;
	// std::cout << tamanho << std::endl;////////////////////////////////////////////////////////////////////
	std::string message = read_file(input);
	std::vector<std::string> block_message = split_message(message, tamanho);
	std::vector<std::string> code_bin_number = block_message_2_bin_number(block_message);
	if((int)(code_bin_number.back()).length()!=tamanho*8){
		code_bin_number[code_bin_number.size()-1] = zero_complete(code_bin_number.back(),tamanho*8-(code_bin_number.back()).length());
	}
	std::vector<BigInteger> code_dec_number = block_bin_number_2_dec_number(code_bin_number);
	std::vector<BigInteger> block_encrypt_data = block_dec_number_2_encrypt_data(code_dec_number,n,e);
	write_cipher_in_file(output, block_encrypt_data);
}

std::vector<std::string> RSA::split_message(std::string message, int size_split){
	std::vector<std::string> block_message_return;
	int n=0;
	int size_message = message.length();
	while(n<size_message){
		block_message_return.push_back(std::string(message,n,size_split));
		n+=size_split;
	}
	return block_message_return;
}

std::vector<std::string> RSA::block_message_2_bin_number(std::vector<std::string> block_message){
	std::vector<std::string> code_bin_number_return;
	int i;
	for(i=0;i<(int)block_message.size();i++){
		code_bin_number_return.push_back(string_2_bin_number(block_message[i]));
	}
	return code_bin_number_return;
}
std::string RSA::string_2_bin_number(std::string parcer_message){
	std::string parcer_code_bin_number = "";
	int i;
	for(i=0;i<(int)parcer_message.length();i++){
		parcer_code_bin_number = parcer_code_bin_number + dec_number_2_bin_number((int)parcer_message[i]);
	}
	return parcer_code_bin_number;
}

std::string RSA::dec_number_2_bin_number(BigInteger dec_number){
	std::string bin_number  = "";
	int length = length_bin_number(dec_number);
	// std::cout << length << std::endl;////////////////////////////////////////////////////////////////////
	BigInteger teste_value = (pow_BI(2,length-1));
	int i;
	// std::cout << dec_number << std::endl;
	for(i=0;i<length;i++){
		if(teste_value <= dec_number){
			bin_number = bin_number + "1";
			dec_number = dec_number - teste_value;
		}else{
			bin_number = bin_number + "0";
		}
		teste_value = teste_value / 2;
	}
	// std::cout << bin_number << std::endl;
	return bin_number;
}

int RSA::length_bin_number(BigInteger dec_number){
	int length_return = 8;
	while(dec_number > (pow_BI(2,length_return)-1)){
		length_return+=8;
	}
	return length_return;
}

BigInteger RSA::pow_BI(BigInteger n, BigInteger a){
	if(a.toInt()==0)
		return 1;
	if(a.toInt()==1)
		return n;
	if(a.toInt()==2)
		return n*n;
	if(mod_BI(a,2).toInt()==1)
		return pow_BI(pow_BI(n,a/2),2)*n;
	return pow_BI(pow_BI(n,a/2),2);
}

BigInteger zero = 0;
BigInteger um   = 1;
BigInteger dois = 2;
BigInteger RSA::pow_BI_Mod(BigInteger n, BigInteger a, BigInteger m){
	if(a==zero)
		return 1;
	if(a==um)
		return mod_BI(n,m);
	if(a==dois)
		return mod_BI(n,m)*mod_BI(n,m);
	if(mod_BI(a,2).toInt()==1)
		return mod_BI(mod_BI(pow_BI_Mod(mod_BI(pow_BI_Mod(mod_BI(n,m),a/2,m),m),2,m),m)*mod_BI(n,m),m);
	return mod_BI(pow_BI_Mod(mod_BI(pow_BI_Mod(mod_BI(n,m),a/2,m),m),2,m),m);
}

std::string RSA::zero_complete(std::string atual_bin_number, int size_last){
	int i;
	for(i=0;i<size_last;i++){
		atual_bin_number = atual_bin_number + "0";
	}
	return atual_bin_number;
}

std::vector<BigInteger> RSA::block_bin_number_2_dec_number(std::vector<std::string> code_bin_number){
	std::vector<BigInteger> block_dec_number_return;
	int i;
	for(i=0;i<(int)code_bin_number.size();i++){
		block_dec_number_return.push_back(bin_number_2_dec_number(code_bin_number[i]));
	}
	return block_dec_number_return;
}

BigInteger RSA::bin_number_2_dec_number(std::string bin_number){
	BigInteger dec_number = 0;
	int length = bin_number.length();
	BigInteger teste_value = pow_BI(2,length-1);
	int i;
	for(i=0;i<length;i++){
		if(bin_number[i] == '1'){
			dec_number = dec_number + teste_value;
		}
		teste_value = teste_value/2;
	}
	return dec_number;
}

std::vector<BigInteger> RSA::block_dec_number_2_encrypt_data(std::vector<BigInteger> code_dec_number, BigInteger n, BigInteger e){
	std::vector<BigInteger> block_encrypt_data_return;
	int i;
	for(i=0;i<(int)code_dec_number.size();i++){
		block_encrypt_data_return.push_back(dec_number_2_encrypt_data(code_dec_number[i],n,e));
	}
	return block_encrypt_data_return;
}

BigInteger RSA::dec_number_2_encrypt_data(BigInteger dec_number, BigInteger n, BigInteger e){
	// return mod_BI(pow_BI(dec_number,e),n);
	return pow_BI_Mod(dec_number,e,n);
}

BigInteger RSA::mod_BI(BigInteger n, BigInteger a){
	return (n-((n/a)*a));
}

std::string RSA::read_file(std::string file_name){
	char ch;
	std::string input_message;
	FILE *arq;
	arq = fopen(file_name.c_str(),"r");
	if(arq == NULL){
		std::cout << "Error! Could not open file.\n";
	}else{
		while((ch=fgetc(arq))!=EOF){
			input_message = input_message + ch;
		}
	}
	fclose(arq);
	return input_message;
}

void RSA::write_cipher_in_file(std::string file_name, std::vector<BigInteger> block_encrypt_data){
	int i;
	std::string buffer;
	FILE *arq;
	arq = fopen(file_name.c_str(),"w");
	if(arq == NULL){
		std::cout << "Error! Could not open file.\n";
	}else{
		for(i=0;i<(int)block_encrypt_data.size()-1;i++){
			buffer = bigIntegerToString(block_encrypt_data[i]);
			fprintf(arq,"%s\n",buffer.c_str());
		}
		buffer = bigIntegerToString(block_encrypt_data[i]);
		fprintf(arq,"%s",buffer.c_str());
	}
	fclose(arq);
}

void RSA::write_message_decipher_in_file(std::string file_name, std::string message_decrypt){
	FILE *arq;
	arq = fopen(file_name.c_str(),"w");
	if(arq == NULL){
		std::cout << "Error! Could not open file.\n";
	}else{
		fprintf(arq,"%s",message_decrypt.c_str());
	}
	fclose(arq);
}

std::vector<BigInteger> RSA::read_file_cipher(std::string file_name){
	char ch;
	std::string input_message = "";
	std::vector<BigInteger> block_encrypt_data_return;
	FILE *arq;
	arq = fopen(file_name.c_str(),"r");
	if(arq == NULL){
		std::cout << "Error! Could not open file.\n";
	}else{
		while((ch=fgetc(arq))!=EOF){
			if(ch=='\n'){
				block_encrypt_data_return.push_back(stringToBigInteger(input_message));
				input_message = "";
			}else{
				input_message = input_message + ch;
			}
		}
		block_encrypt_data_return.push_back(stringToBigInteger(input_message));
	}
	fclose(arq);
	return block_encrypt_data_return;
}

void RSA::decrypt(std::string input, std::string output, BigInteger n, BigInteger d){
	std::vector<BigInteger> block_encrypt_data = read_file_cipher(input);
	std::vector<BigInteger> code_dec_number = block_dec_number_2_encrypt_data(block_encrypt_data,n,d);
	std::vector<std::string> code_bin_number = block_dec_number_2_bin_number(code_dec_number);
	std::vector<std::string> block_message = block_bin_number_2_parcer_message(code_bin_number);
	std::string message_decrypt = block_message_2_single_message(block_message);
	write_message_decipher_in_file(output,message_decrypt);
}

std::vector<std::string> RSA::block_dec_number_2_bin_number(std::vector<BigInteger> code_dec_number ){
	std::vector<std::string> code_bin_number_return;
	int i;
	for(i=0;i<(int)code_dec_number.size();i++){
		code_bin_number_return.push_back(dec_number_2_bin_number(code_dec_number[i]));
	}
	return code_bin_number_return;
}

std::vector<std::string> RSA::block_bin_number_2_parcer_message(std::vector<std::string> code_bin_number){
	std::vector<std::string> block_parcer_message_return;
	int i;
	for(i=0;i<(int)code_bin_number.size();i++){
		block_parcer_message_return.push_back(bin_number_2_parcer_message(code_bin_number[i]));
	}
	return block_parcer_message_return;
}

std::string RSA::bin_number_2_parcer_message(std::string bin_number){
	std::string parcer_message_return = "";
	int i;
	// std::cout << bin_number << " - ";
	// std::cout << (int)bin_number.length()/8 << std::endl;
	for(i=0;i<(int)bin_number.length()/8;i++){
		parcer_message_return = parcer_message_return + (char)(bin_number_2_dec_number(std::string(bin_number,i*8,8))).toInt();
	}
	return parcer_message_return;
}

std::string RSA::block_message_2_single_message(std::vector<std::string> block_message){
	std::string message_return = "";
	int i;
	for(i=0;i<(int)block_message.size();i++){
		message_return = message_return + block_message[i];
	}
	return message_return;
}

//The magic happend here
BigInteger RSA::brute_force_attack(BigInteger n, BigInteger e){
	this->p = this->sqrt(n);
	if(mod_BI(this->p,2)==0){
		this->p--;
	}
	this->q = n/this->p;
	std::cout << n << std::endl;
	if(length_bin_number(n)>63){
		std::cout << ">63: " << this->p << std::endl; 
		while(this->p*this->q != n){
			this->p -= 2;
			this->q = n/this->p;
		}
	}else{
		std::cout << "<63: " << this->p << std::endl;
		//converte tudo pra unsigned long long
		unsigned long long n_ull = n.toUnsignedLLong();
		unsigned long long p_ull = p.toUnsignedLLong();
		unsigned long long q_ull = q.toUnsignedLLong();
		while(p_ull*q_ull != n_ull){
			p_ull -= 2;
			q_ull = n_ull/p_ull;
		}
		//converte tudo pra BigInteger denovo
		n = n_ull;
		p = p_ull;
		q = q_ull;
	}
	this->alpha = (this->p-1)*(this->q-1);
	this->d = choose_d(e,this->alpha);
	return this->d;




	// toUnsignedLong



	// BigInteger p_local;
	// BigInteger q_local;
	// BigInteger d_local;
	// BigInteger alpha_local;

	// p_local = this->sqrt(n);
	// if(mod_BI(p_local,2)==0){
	// 	p_local = p_local - 1;
	// }
	// q_local = n/p_local;
	// std::cout << p_local << std::endl;
	// while(p_local*q_local != n){
	// 	p_local = p_local - 2;
	// 	q_local = n/p_local;
	// }
	// std::cout << p_local << std::endl;
	// alpha_local = (p_local-1)*(q_local-1);
	// d_local = choose_d(e,alpha_local);
	// return d_local;
}

BigInteger RSA::next_prime(BigInteger p){
	// if(mod_BI(p,2)==0)
	// 	p++;
	// else
		p+=2;
	while(is_prime_number(p,40)==0){
		p+=2;
	}
	return p;
}

BigInteger RSA::discovery_q(BigInteger p, BigInteger n){
	return n/p;
}

BigInteger RSA::sqrt(BigInteger number) {
	BigUnsigned a = 1;
	// std::cout << number << std::endl;
	BigUnsigned n = stringToBigUnsigned(bigIntegerToString(number));
	n.bitShiftRight(n,5);
	BigUnsigned b = n + 8;
	n = stringToBigUnsigned(bigIntegerToString(number));
	while(b >= a){
		BigUnsigned m = a + b;
		m.bitShiftRight(m,1);
		if((m*m) > n){
			b = m - 1;
		}
		else{
			a = m + 1;
		}
	}
	a--;
	return stringToBigInteger(bigUnsignedToString(a));
}