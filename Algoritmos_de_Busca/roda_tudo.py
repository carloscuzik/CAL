#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
from subprocess import call

arquivos = []
arquivos+= ["teste_altomatizado.py"]
arquivos+= ["compara.py"]
arquivos+= ["gera_grafic.py > grafic"]
arquivos+= ["gera_table.py > table"]

for i in arquivos:
	call("python " + i, shell = True)

