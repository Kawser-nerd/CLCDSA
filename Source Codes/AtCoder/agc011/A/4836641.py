n, c, k = map(int, input().split())
t = [int(input()) for _ in range(n)]
t.sort()
cnt = 0
cur = -k
num = 1
for i in range(n):
    if t[i] > cur + k or num == c:
        cur = t[i]
        cnt += 1
        num = 1
    else:
        num += 1
print(cnt)