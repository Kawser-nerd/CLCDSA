import collections

n = int(input())
a = collections.Counter(list(map(int, input().split()))).most_common()
ans = 0
for i, j in a:
    if i > j:
        ans += j
    if i < j:
        ans += j - i
print(ans)