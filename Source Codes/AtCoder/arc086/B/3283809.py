N = int(input())
a = list(map(int, input().split()))
ans = []

if max(a) > 0 > min(a):
    max_i, min_i = a.index(max(a)), a.index(min(a))
    if abs(a[max_i]) > abs(a[min_i]):
        for i in range(N):
            if i == max_i:
                continue
            a[i] += a[max_i]
            ans.append((max_i+1, i+1))
    else:
        for i in range(N):
            if i == min_i:
                continue
            a[i] += a[min_i]
            ans.append((min_i+1, i+1))

if min(a) >= 0:
    for i in range(1, N):
        ans.append((i, i+1))
else:
    for i in range(N-1, 0, -1):
        ans.append((i+1, i))

print(len(ans))
for l in ans:
    print(*l)