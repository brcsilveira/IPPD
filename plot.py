import pandas as pd
import matplotlib.pyplot as plt
import sys

if len(sys.argv) < 2:
    print("Uso: python3 plot.py results.csv")
    exit(1)

df = pd.read_csv(sys.argv[1])
print("Arquivo carregado, gráficos serão implementados depois das tarefas.")
