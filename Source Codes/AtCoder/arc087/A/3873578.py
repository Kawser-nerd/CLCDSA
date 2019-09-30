import collections

N = int(input())
A = input().split(' ')
counter_A = collections.Counter(A)

ans = 0
for k, v in counter_A.items():
    if int(k) <= v:
        ans += v - int(k)
    else:
        ans += v
print(ans)