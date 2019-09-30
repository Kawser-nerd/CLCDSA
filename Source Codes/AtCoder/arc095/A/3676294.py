n = int(input())
x = list(map(int, input().split()))

use = x[::]
use.sort()

l = use[n//2-1]
r = use[n//2]
for i in x:
    if i <= l:
        print(r)
    else:
        print(l)