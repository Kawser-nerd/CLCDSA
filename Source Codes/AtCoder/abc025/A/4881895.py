import itertools
S=input()
N=int(input())

arr = sorted(list(S))

names = [x+y for x,y in itertools.product(arr, arr)]
print(names[N-1])