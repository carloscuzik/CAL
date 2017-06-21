#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

num_amostra = 10

arquivo = open("saida")
arquivo = arquivo.readlines()


resultados = []

for i in range(num_amostra*3):
	resultados += [(arquivo[i].split('\n'))[0]]
# print(resultados)

print("Highcharts.chart('container', {\n", end="")
print("\tchart: {")
print("\t\ttype: 'spline'")
print("\t},")

print("\ttitle: {\n", end="")
print("\t\ttext: 'Gráfico para comparação dos tempos de Inserção'\n", end="")
print("\t},\n", end="")

print("\txAxis: {\n", end="")
print("\t\tcategories: [",end="")

for i in range(32,36):
	print(str(i)+",",end="")
print(36,end="")

print("]\n", end="")
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
print("\t\tspline: {")
print("\t\t\tlineWidth: 5,")
print("\t\t\tmarker: {")
print("\t\t\t\tenabled: false")
print("\t\t\t}")
print("\t\t}")
print("\t},\n", end="")

print("\tseries: [\n", end="")

print("\t{\n", end="")
print("\t\tname: 'Criptar',\n", end="")
print("\t\tdata: [",end="")
for i in range(num_amostra-1):
	print(str(resultados[i*3])+",", end="")
print(resultados[(num_amostra-1)*3], end="")
print("],")
print("\t},{\n", end="")
print("\t\tname: 'Decriptar',\n", end="")
print("\t\tdata: [",end="")
for i in range(num_amostra-1):
	print(str(resultados[i*3+1])+",", end="")
print(resultados[(num_amostra-1)*3+1], end="")
print("],")
print("\t},{\n", end="")
print("\t\tname: 'Força Bruta',\n", end="")
print("\t\tdata: [",end="")
for i in range(num_amostra-1):
	print(str(resultados[i*3+2])+",", end="")
print(resultados[(num_amostra-1)*3+2], end="")
print("]")

print("\t}]\n", end="")
print("});\n", end="")
