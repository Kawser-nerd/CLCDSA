n = int(input())
t = [int(input()) for i in range(n)]
t.sort()
ans = 0
time = 0
for i in range(n):
    ans += (time+t[i])
    time += t[i]
print(ans)
di = {}
li = [False for i in range(1,100001)]
for i in t:
    if li[i]:
        di[i] += 1
    else:
        di[i] = 1
        li[i] = True
ans = 1
for i in di.values():
    for j in range(1,i+1):
        ans *= j
        ans %= 1000000007
print(ans)