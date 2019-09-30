n = int(input())

l = []
r = []
for i in range(n):
    lt, rt = map(int,input().split())
    l.append(lt)
    r.append(rt)

l.append(0)
r.append(0)

l.sort()
r.sort()
l.reverse()

ans = 0
i = 0
while r[i]<l[i]:
    ans += 2*(l[i] - r[i])
    i+=1

print(ans)