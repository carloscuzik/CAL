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

for i in type_ini:
	for j in arq:
		saida_gerada = "Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt"
		# saida_do_prof = open("Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt")
		saida_do_prof= "Saidas-Prof/saida-" + str(j) + ".txt"
		print("diff " + saida_gerada + " " + saida_do_prof)
		# call("diff " + saida_gerada + " " + saida_do_prof, shell = True)
