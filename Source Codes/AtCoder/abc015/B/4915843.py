#14
import math
n = int(input())
a = list(map(int,input().split()))
print(math.ceil(sum(a)/(n-a.count(0))))