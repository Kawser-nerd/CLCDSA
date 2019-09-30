import math    
n = int(input())
a = list(map(int,input().split()))
cnt = 0
res = 0
for i in a:
    if i!=0:
        cnt += 1
        res += i
print(math.ceil(res/cnt))