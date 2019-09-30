N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]
ls = [0]
rs = [0]
for l,r in src:
    ls.append(l)
    rs.append(r)
ans = 0
for l,r in zip(reversed(sorted(ls)),sorted(rs)):
    if l <= r: break
    ans += 2*(l-r)
print(ans)