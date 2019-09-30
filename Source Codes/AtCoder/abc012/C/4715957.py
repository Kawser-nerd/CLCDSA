from itertools import product

N = int(input())
diff = 2025 - N

for i, j in product(range(1, 10), range(1, 10)):
    if i*j == diff:
        print("{} x {}".format(i, j))