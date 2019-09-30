from itertools import product
N = int(input())
ls = ['a', 'b', 'c']
for x in product(ls, repeat=N):
    print(''.join(x), sep='\n')