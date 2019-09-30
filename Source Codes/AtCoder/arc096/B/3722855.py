N,C = map(int,input().split())
src = [tuple(map(int,input().split())) for i in range(N)]

csum_r = [0]
cmax_r1 = [0]
cmax_r2 = [0]
for x,v in src:
    csum_r.append(csum_r[-1] + v)
    cmax_r1.append(max(cmax_r1[-1], csum_r[-1] - x))
    cmax_r2.append(max(cmax_r2[-1], csum_r[-1] - 2*x))

csum_l = [0]
cmax_l1 = [0]
cmax_l2 = [0]
for x,v in reversed(src):
    x = C-x
    csum_l.append(csum_l[-1] + v)
    cmax_l1.append(max(cmax_l1[-1], csum_l[-1] - x))
    cmax_l2.append(max(cmax_l2[-1], csum_l[-1] - 2*x))

ans = max(cmax_r1[-1], cmax_l1[-1])
for a,b in zip(cmax_r2, cmax_l1[::-1]):
    ans = max(ans, a+b)
for a,b in zip(cmax_l2, cmax_r1[::-1]):
    ans = max(ans, a+b)

print(ans)