import numpy as np
import sys
from subprocess import run, PIPE

MAX_ROWS = 10
MAX_COLS = 10

class colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def create_random_matrix(rows: int, cols: int) -> np.array:
    return np.random.random((rows, cols))

def equalMatrices(A: list[list[float]], B: list[list[float]]) -> bool:
    comparison = A == B
    return comparison.all()

matrices = []

num_tests = 100
program = run(["./test"] + [str(num_tests + 1)], stdout=PIPE,stderr=PIPE,
                    input="test", encoding='ascii')

output = list(program.stdout.split(','))

rows1 = int(output[0])

rows2 = int(output[1])

cols1 = int(output[2])
cols2 = int(output[3])

rows_final = rows1
cols_final = cols2


offset = 0
output = output[4:-1]

num_passed = 0

for x in range(num_tests):

    first = list(np.zeros((rows1, cols1), dtype=float))
    second = list(np.zeros((rows2, cols2), dtype=float))
    product = list(np.zeros((rows_final, cols_final), dtype=float))

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

    offset += rows_final * cols_final

    if (x != num_tests - 1):
        rows1 = int(output[offset])
        rows2 = int(output[offset + 1])

        cols1 = int(output[offset + 2])
        cols2 = int(output[offset + 3])

        rows_final = rows1
        cols_final = cols2

    offset += 4

    if equalMatrices(np.array(product), np.dot(first, second)):
        print(colors.OKGREEN + "[OK] Passed test {}, size = ({}, {}) * ({}, {}) ".format(x, rows1, cols1, rows2, cols2) + colors.ENDC)
        num_passed += 1

    else:
        print(colors.FAIL + "[FAIL] Didnt pass test {}, size = ({}, {}) * ({}, {}) ".format(x, rows1, cols1, rows2, cols2) + colors.ENDC)

            #output_matrix = np.array(list(map(float, output.stdout.split(','))))

if num_passed == num_tests:
    print(colors.OKGREEN + f"Passed {num_passed} / {num_passed} tests" + colors.ENDC)

else:
    print(colors.WARNING + f"Passed {num_passed} / {num_tests} tests" + colors.ENDC)



