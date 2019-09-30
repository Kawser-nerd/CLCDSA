from collections import Counter
N,K = map(int,input().split())
A = list(map(int,input().split()))
c = Counter(A)
values_list = list(c.values())
values_list.sort()
ans = 0
for i in range(len(values_list)-K):
    ans += values_list[i]
print(ans)