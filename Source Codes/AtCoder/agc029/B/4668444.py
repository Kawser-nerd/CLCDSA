n = int(input())
a = list(map(int,input().split()))
a.sort()
from collections import Counter
dic = Counter(a)
ans = 0
for k in range(len(a)-1,-1,-1):
    if dic[a[k]]==0:
        continue
    dic[a[k]] -= 1
    t = 2**a[k].bit_length()-a[k]
    if dic[t]:
        dic[t] -= 1
        ans += 1
print(ans)