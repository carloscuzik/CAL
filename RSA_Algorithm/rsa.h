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

class RSA{
private:
	BIgInteger p;
	BIgInteger q;
	BIgInteger n;
	BIgInteger alpha;
	int e;
	BIgInteger d;
public:
	RSA();
	~RSA();
	
};

#endif /* RSA_H */