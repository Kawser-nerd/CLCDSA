from collections import Counter
h, w, n = map(int, input().split())
d = Counter()
for _ in range(n):
    a, b = map(int, input().split())
    for i in range(3):
        for j in range(3):
            if w > b+j-1 > 1 < a+i-1 < h:
                d[(a+i,b+j)] += 1
ans = Counter()
for i in d.values():
    ans[i] += 1
print((h-2)*(w-2) - sum(ans.values()))
for i in range(1,10):
    print(ans[i])