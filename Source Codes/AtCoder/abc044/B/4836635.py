import collections
w = list(input())
l = collections.Counter(w)
ans = "Yes"
for v in l.values():
    if v % 2 == 1:
        ans = "No"
print(ans)