N = int(input())
b = list(map(int, input().split()))
a = []
for i in range(N):
    k = N - i
    for j in range(k):
        l = k - j
        if b[l-1] == l:
            a.append(l)
            del b[l-1]
            break
    if len(b) == k:
        break
if len(b) == 0:
    for i in reversed(range(N)):
        print(a[i])
else:
    print(-1)