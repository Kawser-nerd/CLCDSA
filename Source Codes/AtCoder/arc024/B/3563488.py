n = int(input())
co = [int(input()) for i in range(n)]
for i in range(n):
    co.append(co[i])
m = 0
for i in range(n):
    if co[i] == 0:
        m += 1
if m == 0 or m == n:
    print(-1)
    quit()
ans = 0
key = co[0]
s = 1
for i in range(1,2*n):
    if co[i] == key:
        s += 1
    else:
        key = co[i]
        ans = max(ans, (s-1)//2+1)
        s = 1
ans = max(ans, s//2)
print(ans)