#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

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

print()
print()
print()
print("Highcharts.chart('container', {\n", end="")

print("\ttitle: {\n", end="")
print("\t\ttext: 'Gráfico para comparação dos tempos de Inserção'\n", end="")
print("\t},\n", end="")

print("\txAxis: {\n", end="")
print("\t\tcategories: [5000,25000,50000,100000,100000]\n", end="")
print("\t},\n", end="")

print("\tyAxis: {\n", end="")
print("\t\ttitle: {\n", end="")
print("\t\t\ttext: 'Tempo (s)'\n", end="")
print("\t\t}\n", end="")
print("\t},\n", end="")
print("\tlegend: {\n", end="")
print("\t\tlayout: 'vertical',\n", end="")
print("\t\talign: 'right',\n", end="")
print("\t\tverticalAlign: 'middle'\n", end="")
print("\t},\n", end="")

print("\tplotOptions: {\n", end="")
print("\t},\n", end="")

print("\tseries: [\n", end="")

coluna = 1
# print("Inserção")

print("\t{\n", end="")
print("\t\tname: 'linear',\n", end="")
print("\t\tdata: [" + arquivo_linear_line[0][coluna] + "," + arquivo_linear_line[1][coluna] + "," + arquivo_linear_line[2][coluna] + "," + arquivo_linear_line[3][coluna] + "," + arquivo_linear_line[4][coluna] + "],")
print("\t},{\n", end="")
print("\t\tname: 'binário',\n", end="")
print("\t\tdata: [" + arquivo_binario_line[0][coluna] + "," + arquivo_binario_line[1][coluna] + "," + arquivo_binario_line[2][coluna] + "," + arquivo_binario_line[3][coluna] + "," + arquivo_binario_line[4][coluna] + "],")
print("\t},{\n", end="")
print("\t\tname: 'hash',\n", end="")
print("\t\tdata: [" + arquivo_hash_line[0][coluna] + "," + arquivo_hash_line[1][coluna] + "," + arquivo_hash_line[2][coluna] + "," + arquivo_hash_line[3][coluna] + "," + arquivo_hash_line[4][coluna] + "]")
# print("\t}\n", end="")


print("\t}]\n", end="")
print("});\n", end="")

print()
print()
print()
print("Highcharts.chart('container', {\n", end="")

print("\ttitle: {\n", end="")
print("\t\ttext: 'Gráfico para comparação dos tempos de Busca'\n", end="")
print("\t},\n", end="")

print("\txAxis: {\n", end="")
print("\t\tcategories: [1000,10000,10000,25000,75000]\n", end="")
print("\t},\n", end="")

print("\tyAxis: {\n", end="")
print("\t\ttitle: {\n", end="")
print("\t\t\ttext: 'Tempo (s)'\n", end="")
print("\t\t}\n", end="")
print("\t},\n", end="")
print("\tlegend: {\n", end="")
print("\t\tlayout: 'vertical',\n", end="")
print("\t\talign: 'right',\n", end="")
print("\t\tverticalAlign: 'middle'\n", end="")
print("\t},\n", end="")

print("\tplotOptions: {\n", end="")
print("\t},\n", end="")

print("\tseries: [\n", end="")

coluna = 2
# print("Inserção")

print("\t{\n", end="")
print("\t\tname: 'linear',\n", end="")
print("\t\tdata: [" + arquivo_linear_line[0][coluna] + "," + arquivo_linear_line[1][coluna] + "," + arquivo_linear_line[2][coluna] + "," + arquivo_linear_line[3][coluna] + "," + arquivo_linear_line[4][coluna] + "],")
print("\t},{\n", end="")
print("\t\tname: 'binário',\n", end="")
print("\t\tdata: [" + arquivo_binario_line[0][coluna] + "," + arquivo_binario_line[1][coluna] + "," + arquivo_binario_line[2][coluna] + "," + arquivo_binario_line[3][coluna] + "," + arquivo_binario_line[4][coluna] + "],")
print("\t},{\n", end="")
print("\t\tname: 'hash',\n", end="")
print("\t\tdata: [" + arquivo_hash_line[0][coluna] + "," + arquivo_hash_line[1][coluna] + "," + arquivo_hash_line[2][coluna] + "," + arquivo_hash_line[3][coluna] + "," + arquivo_hash_line[4][coluna] + "]")
# print("\t}\n", end="")


print("\t}]\n", end="")
print("});\n", end="")