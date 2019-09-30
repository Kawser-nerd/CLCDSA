n = int(input())
s = []

geta = 0
for i in range(n):
    a = int(input())
    if a % 10 == 0:
        geta += a
    else:
        s.append(a)

n = len(s)
s.sort(reverse=True)

tmp = sum(s)

ruiseki = [tmp]
for i in range(n-1):
    ruiseki.append(ruiseki[-1] - s[i])

ans = 0
def DFS(depth, now):
    global ans

    if depth == n:
        if now%10 != 0:
            ans = max(ans, now)
        return
    if now + ruiseki[depth] <= ans:
        return
    DFS(depth+1, now+s[depth])
    DFS(depth+1, now)
DFS(0,0)
if ans != 0:
    ans += geta
print(ans)