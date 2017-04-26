#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

valores = []
valores+= [[5000,25000,50000,100000,100000]]
valores+= [[1000,10000,10000,25000,75000]]

titulo = []
titulo+= ["Tempos de Inserção"]
titulo+= ["Tempos de Busca"]

arquivo_linear = open("Results/linear.txt")
arquivo_linear = arquivo_linear.readlines()
arquivo_binario = open("Results/binario.txt")
arquivo_binario = arquivo_binario.readlines()
arquivo_hash = open("Results/hash.txt")
arquivo_hash = arquivo_hash.readlines()

arquivo_linear_line = []
arquivo_binario_line = []
arquivo_hash_line = []

for i in range(5):
	arquivo_linear_line += [arquivo_linear[i].split(' ')]
	arquivo_binario_line += [arquivo_binario[i].split(' ')]
	arquivo_hash_line += [arquivo_hash[i].split(' ')]

for coluna in [1,2]:
	print("\t\\begin{table}[h!]")
	print("\t\t\\centering")
	print("\t\t\\begin{tabular}{| c || c | c | c | c | c |}")
	print("\t\t\t\\hline")
	print("\t\t\t\t\\textbf{Tipo} & \\textbf{" + str(valores[coluna-1][0]) + "} & \\textbf{" + str(valores[coluna-1][1]) + "} & \\textbf{" + str(valores[coluna-1][2]) + "} & \\textbf{" + str(valores[coluna-1][3]) + "} & \\textbf{" + str(valores[coluna-1][4]) + "} \\\\")
	print("\t\t\t\\hline")
	print("\t\t\t\tLinear & " + arquivo_linear_line[0][coluna] + " & " + arquivo_linear_line[1][coluna] + " & " + arquivo_linear_line[2][coluna] + " & " + arquivo_linear_line[3][coluna] + " & " + arquivo_linear_line[4][coluna] + "\\\\")
	print("\t\t\t\\hline")
	print("\t\t\t\tBinário & " + arquivo_binario_line[0][coluna] + " & " + arquivo_binario_line[1][coluna] + " & " + arquivo_binario_line[2][coluna] + " & " + arquivo_binario_line[3][coluna] + " & " + arquivo_binario_line[4][coluna] + "\\\\")
	print("\t\t\t\\hline")
	print("\t\t\t\tHash & " + arquivo_hash_line[0][coluna] + " & " + arquivo_hash_line[1][coluna] + " & " + arquivo_hash_line[2][coluna] + " & " + arquivo_hash_line[3][coluna] + " & " + arquivo_hash_line[4][coluna] + "\\\\")
	print("\t\t\t\\hline")
	print("\t\t\\end{tabular}")
	print("\t\t\\caption{" + titulo[coluna-1] + "}")
	print("\t\t\\label{table:1}")
	print("\t\\end{table}")
	print("\n\n\n")