#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from subprocess import call

type_ini = [1,2,3]

arq = [1,2,3,4,5]

name = []
name+= ["linear"]
name+= ["binario"]
name+= ["hash"]

print("arquivos que estão com os resultados errado")
for i in type_ini:
	for j in arq:
		c = False
		b = 0
		saida_gerada = open("Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt")
		saida_gerada = saida_gerada.readlines()
		saida_do_prof= open("Saidas-Prof/saida-" + str(j) + ".txt")
		saida_do_prof = saida_do_prof.readlines()
		a = 0
		for k in saida_do_prof:
			a = a+1
		for k in range(a):
			if(saida_do_prof[k]!=saida_gerada[k]):
				b = b+1
				c = True
		if(c):
			print("Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt" + " com " + str(b) + "/" + str(a) + " linhas diferentes")

