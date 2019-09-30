n = int(input())
a = [int(i) for i in input().split()]
c = list(range(min(a), max(a) + 1))
d = []
for c_ in c:
    ans = int(sum([((a_ - c_) ** 2) for a_ in a]))
    d.append(ans)
print(min(d))