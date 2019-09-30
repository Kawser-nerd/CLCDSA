import bisect
import math
MAX = 10**5

res = [3]
def prime(x):
    for i in range(2,int(math.sqrt(x))+1):
        if x%i == 0:
            return False
    return True
for i in range(3,MAX,2):
    if prime(i) and prime(i*2-1):
        res.append(i*2-1)

q = int(input())

for i in range(q):
    l,r = map(int,input().split())
    print(bisect.bisect_right(res,r)-bisect.bisect_left(res,l))