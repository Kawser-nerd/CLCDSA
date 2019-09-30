def inpl(): return list(map(int, input().split()))
ans = 0
R, C, D = inpl()
for i in range(min(R, D+1)):
    I = inpl()[(D+i)%2:D-i+1:2]
    # print(I)
    ans = max(ans, max(I + [0]))
print(ans)