n=int(input())
a=list(map(int,input().split()))
import math
print(math.ceil(sum(a)/(len(a)-a.count(0))))