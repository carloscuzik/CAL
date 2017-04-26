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
		# print("./hocus_pocus " + str(i) + " < Entradas/entrada-" + str(j) + ".txt > Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt")
		call("./hocus_pocus " + str(i) + " < Entradas/entrada-" + str(j) + ".txt > Saidas/saida-" + str(name[i-1]) + "-" + str(j) + ".txt", shell = True)

