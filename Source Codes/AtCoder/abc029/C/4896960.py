import itertools

n=int(input())

A=['a','b','c']

X=list(itertools.product(A,repeat=n))

X.sort()

for x in X:
    print(''.join(x))