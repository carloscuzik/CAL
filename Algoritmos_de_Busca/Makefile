CC=g++
override CFLAGS+=-DIL_STD -c -Wall -Og -g --std=c++11
override CFLAGSL+= 
override LDFLAGS+= 

SOURCES=							\
    main.cpp						\
    lista_encadiada.cpp				\
    arvore_avl.cpp					\
    hash_encadiado.cpp				\
    node.cpp

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