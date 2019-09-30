n,k = map(int, input().split())
r = list(map(int, input().split()))
r.sort(reverse=True)
del r[k:]
score = 0
r.reverse()
for i in range(len(r)):
    score = (score + r[i]) / 2
print(score)