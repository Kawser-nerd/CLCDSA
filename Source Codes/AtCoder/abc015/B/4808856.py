import math
n=int(input())
a=list(map(int, input().split()))
#print(sum(a) // (n-a.count(0)) + (sum(a) % (n-a.count(0)) != 0))
print(math.ceil(sum(a) / (n-a.count(0))))