n = int(input())
p = [int(input()) for _ in range(n)]
p_m = [0]*n
for i,j in enumerate(p):
    p_m[j-1] = i
res = -10**9
cnt = 0
prev = -1
for i in p_m:
    if prev <= i:
        cnt += 1
        prev = i
    else:
        res = max(res, cnt)
        cnt = 1
        prev = i
else:
    res = max(res, cnt)
print(n - res)