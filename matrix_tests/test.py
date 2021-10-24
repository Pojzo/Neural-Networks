import numpy as np
import sys
from subprocess import run, PIPE

MAX_ROWS = 10
MAX_COLS = 10


def create_random_matrix(rows: int, cols: int) -> np.array:
    return np.random.random((rows, cols))

def equalMatrices(A: list[list[float]], B: list[list[float]]) -> bool:
    comparison = A == B
    print(comparison)
    return comparison.all()

matrices = []

num_tests = 1

program = run(["./test"], stdout=PIPE,stderr=PIPE,
                    input="test", encoding='ascii')

output = list(program.stdout.split(','))
num_matrices = int(output[4])

rows1 = int(output[0])

rows2 = int(output[1])

cols1 = int(output[2])
cols2 = int(output[3])

rows_final = rows1
cols_final = cols2

first = list(np.zeros((rows1, cols1), dtype=float))
second = list(np.zeros((rows2, cols2), dtype=float))
product = list(np.zeros((rows_final, cols_final), dtype=float))

offset = 0

output = output[4:]

for x in range(num_tests):
    for i in range(rows1):
        for j in range(cols1):
            first[i][j] = output[offset + (i * cols1 + j)]

    offset += rows1 * cols1

    for i in range(rows2):
        for j in range(cols2):
            second[i][j] = output[offset + (i * cols2 + j)]

    offset += rows2 * cols2

    for i in range(rows_final):
        for j in range(cols_final):
            product[i][j] = output[offset + (i * cols_final + j)]

    offset += rows_final + cols_final
    rows1 = int(output[offset])
    rows2 = int(output[offset + 1])

    cols1 = int(output[offset + 2])
    cols2 = int(output[offset + 3])

    rows_final = rows1
    cols_final = cols2

    print(product)
    print(np.dot(first, second))
    if equalMatrices(np.array(product), np.dot(first, second)):
        print("Passed test {}".format(x))

    else:
        print("Didnt pass test {}".format(x))

            #output_matrix = np.array(list(map(float, output.stdout.split(','))))


