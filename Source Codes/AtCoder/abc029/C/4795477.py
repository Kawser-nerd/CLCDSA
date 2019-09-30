from itertools import product

N = int(input())
charlist = [['a', 'b', 'c'] for _ in range(N)]

for i in product(*charlist):
    password = ''
    for j in i:
        password += j
    print(password)