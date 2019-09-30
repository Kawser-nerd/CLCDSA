n,m = [int(i) for i in input().split()]
x = list(map(int, input().split()))

score = max(x) - min(x)

x.sort()

dist = []

for i in range(1,m):
    dif = x[i] - x[i-1]
    dist.append(dif)

dist.sort()

#dist????m-1

if n >= m:
    score = 0
else:
    for i in range(1,n):
        reduce = dist[-i]
        score -= reduce
print(score)