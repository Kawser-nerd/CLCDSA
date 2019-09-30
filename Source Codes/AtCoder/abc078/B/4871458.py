import math
a,b,c=map(int,input().split())
a-=c
print(math.floor(a/(b+c)))