import numpy as np
from subprocess import run, PIPE

MAX_ROWS = 10
MAX_COLS = 10

def create_random_matrix(rows, cols):
    return np.random.random((rows, cols))

matrices = []

for i in range(MAX_ROWS):
    for j in range(MAX_COLS):
        matrices.append(create_random_matrix(i, j))


file = open("test.txt", "w")

output = run(["./test"], stdout=PIPE, stderr=PIPE,
                    input="test", encoding='ascii')

output_matrix = np.array(list(map(float, output.stdout.split(','))))
print(output_matrix)

stderr = output.stderr

