from functools import reduce

N=int(input())
a=list(map(int, input().split()))

m=reduce(lambda x, y: x * y, a)-1
f=sum(map(lambda x: m % x, a))

print(f)