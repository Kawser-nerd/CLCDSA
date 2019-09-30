import math
n=int(input())
data=[tuple(int(i) for i in input().split()) for _ in range(n)][::-1]
ans=0
for i,j in data:
    i+=ans
    ans+=math.ceil(i/j)*j-i
print(ans)