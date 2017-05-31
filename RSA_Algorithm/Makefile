CC=g++
override CFLAGS+=-DIL_STD -c -Wall -g --std=c++11
override CFLAGSL+= -lm -O3
override LDFLAGS+= 

SOURCES=							\
    main.cpp						\
	rsa.cpp							\
	BigInteger.cpp 					\
	BigIntegerAlgorithms.cpp 		\
	BigIntegerUtils.cpp 			\
	BigUnsigned.cpp 				\
	BigUnsignedInABase.cpp

OBJECTS=$(SOURCES:.cpp=.o)

#@echo "Objetos Compilados com sucesso"

EXECUTABLE= hocus_pocus

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(CFLAGSL)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(CFLAGSL)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(EXECUTABLE)