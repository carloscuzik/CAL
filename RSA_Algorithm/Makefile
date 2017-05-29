CC=g++
override CFLAGS+=-DIL_STD -c -Wall -g --std=c++11
override CFLAGSL+= -lm -O3
override LDFLAGS+= 

SOURCES=							\
    main.cpp						\
    rsa.cpp

LIBS=								\
	BigInteger.cc 					\
	BigIntegerAlgorithms.cc 		\
	BigIntegerUtils.cc 				\
	BigUnsigned.cc 					\
	BigUnsignedInABase.cc

OBJECTS=$(SOURCES:.cpp=.o)

#@echo "Objetos Compilados com sucesso"

EXECUTABLE= hocus_pocus

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)