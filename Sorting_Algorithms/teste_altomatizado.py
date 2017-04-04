#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from subprocess import call

type_ini = []
type_ini += [10,20,30,40]

size_v = []
size_v += [25000,50000,75000,100000,1000000]


for j in type_ini:
	for i in range(8):
		for k in size_v:
			#print("./exe" + " " + str(i) + " " + str(j) + " " + str(k))
			call("./exe" + " " + str(i) + " " + str(j) + " " + str(k), shell = True)
