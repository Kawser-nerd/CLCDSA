from itertools import product
N = int(input())
chars = ["a", "b", "c"]

for line in product(chars, repeat=N):
  print("".join(line))