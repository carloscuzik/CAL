/***********************************
 * File name   : main.cpp          *
 * Author      : carloscuzik       *
 * Description : just a main file  *
 *                                 *
 * Open your mind to the FUTURE.   *
 ***********************************/

//include of global libraries 
#include <iostream>
#include <vector>
#include <string>

class BigInteger{
private:

public:
	BigInteger();
	BigInteger(int number_initialization);
	BigInteger(std::string number_initialization);
	~BigInteger();
	void add(BigInteger a);
	void sub(BigInteger a);
	void mul(BigInteger a);
	void div(BigInteger a);
};
