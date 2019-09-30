N = int(input())

if N%2 == 0:
    M = N+1
else:
    M = N+2


ans = 0
for x in range(1, M, 2):
    cnt = 0
    for i in range(1, x+1):
        if x%i == 0:
            cnt += 1
    if cnt == 8:
        ans += 1

print(ans)