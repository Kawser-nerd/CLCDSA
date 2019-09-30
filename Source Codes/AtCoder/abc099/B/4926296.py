from itertools import accumulate as acc
a=[i for i in range(1000)]
a=list(acc(a))

A,B=map(int,input().split())
print(a[B-A]-B)