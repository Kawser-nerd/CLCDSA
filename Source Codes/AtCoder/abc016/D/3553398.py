x1,y1,x2,y2 = map(int,input().split())
r = [x2-x1,y2-y1]
N = int(input())
p = []
for i in range(N):
    p.append(tuple(map(int,input().split())))
ans = 0
for i in range(N):
    p1,q1 = p[i]
    p2,q2 = p[(i+1)%N]
    r0 = [p2-p1,q2-q1]
    r1 = [p1-x1,q1-y1]
    r2 = [p2-x1,q2-y1]
    r3 = [x1-p1,y1-q1]
    r4 = [x2-p1,y2-q1]
    S1 = (r1[0]*r[1]-r1[1]*r[0])*(r2[0]*r[1]-r2[1]*r[0])
    S2 = (r3[0]*r0[1]-r3[1]*r0[0])*(r4[0]*r0[1]-r4[1]*r0[0])
    if S1 < 0 and S2 < 0:
        ans += 1
ans //= 2
ans += 1
print(ans)