import os
import filecmp
from pathlib import Path
from collections import Counter

def calculate_grade(path_input):
  values = {}
  with open(path_input, "r") as f:
    f.readline()
    for line in f:
      positions = line.strip().split(' ')
      first_node = positions[:2]
      first_node_values = f"({first_node[0]},{first_node[1]})";
      second_node = positions[2:]
      second_node_values = f"({second_node[0]},{second_node[1]})";
      if (first_node_values not in values):
        values[first_node_values] = 1
      else:
        values[first_node_values] += 1
      if (second_node_values not in values):
        values[second_node_values] = 1
      else:
        values[second_node_values] += 1
  counts = Counter(values.values())
  print(f"Grados de {path_input}: {counts}")


if __name__ == '__main__':
    PATH_GENERAL_TEST = "./"  # RUTA A LA CARPETA CONTENEDORA DE LOS TESTS
    EXECUTABLE = "mst"  # NOMBRE DEL EJECUTABLE

    path_outputs = os.path.join(PATH_GENERAL_TEST, "output")
    lista_input = []
    nombre_archivos = []
    for archivo in Path(path_outputs).glob("**/*.txt"):
        lista_input.append(archivo)

    for i, path_input in enumerate(lista_input):
        calculate_grade(path_input)
