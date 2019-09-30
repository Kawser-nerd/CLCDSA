N,M = map(int,input().split())
ab = []
for i in range(M):
    ab.append(list(map(int,input().split())))

ab = sorted(ab,key=lambda x : x[1])
end = 0
ans = 0
for y in ab:
    if y[0] >= end:
        ans += 1
        end = y[1]
print(ans)