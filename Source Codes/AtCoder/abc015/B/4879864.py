import math
n = int(input())
a = [int(i) for i in input().split()]
s = sum(a)
num = n - a.count(0)
print(math.ceil(s/num))