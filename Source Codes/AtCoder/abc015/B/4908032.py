from math import ceil
N = int(input())
a = [int(x) for x in input().split() if int(x) != 0]
print(ceil(sum(a)/len(a)))