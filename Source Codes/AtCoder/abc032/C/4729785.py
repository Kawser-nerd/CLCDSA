n, k = map(int, input().split())
s = [int(input()) for _ in range(n)]

if 0 in s:
    print(n)
    exit()
if k == 0:
    print(0)
    exit()

s.append(k+1)

a = 0
b = -1
ans = 0
temp = 1
for i in range(n+1):
    if s[i] > k:
        ans = max(ans, i - a)
        temp = 1
        a = i + 1
        continue
    temp *= s[i]
    if temp > k:
        ans = max(ans, i - a)
        while 1:
            temp //= s[a]
            a += 1
            if temp <= k:
                break
print(ans)