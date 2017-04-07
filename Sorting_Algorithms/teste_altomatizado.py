#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from subprocess import call

type_ini = []
type_ini += [40]

type_o = []
type_o += [7]

size_v = []
size_v += [25000,50000,75000,100000,1000000]


#for j in type_ini:
	#for i in type_o:
		#for k in size_v:
			#print("./exe" + " " + str(i) + " " + str(j) + " " + str(k))
			#call("./exe" + " " + str(i) + " " + str(j) + " " + str(k), shell = True)

#call("./exe 3 10 1000000", shell = True)
call("./exe 0 20 1000000", shell = True)
call("./exe 1 20 1000000", shell = True)
call("./exe 3 20 1000000", shell = True)
call("./exe 0 30 1000000", shell = True)
call("./exe 0 40 1000000", shell = True)
call("./exe 1 40 1000000", shell = True)
call("./exe 3 40 1000000", shell = True)

