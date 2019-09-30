n = int(input())
t = [int(i) for i in input().split()]
v = [int(i) for i in input().split()]

m = [0]*(n+1)
z = [0]*(n+1)
for i in range(n-1,0,-1):
    m[i] = min(v[i], v[i-1], t[i] + m[i+1])
for i in range(1,n):
    z[i] = min(m[i], z[i-1]+t[i-1])

def dist(i):
    lspeed = z[i]
    rspeed = z[i+1]
    ta = v[i] - lspeed
    tb = v[i] - rspeed
    if ta + tb <= t[i]: # ???????
        c = (lspeed+v[i])*ta/2 + v[i]*(t[i]-ta-tb) + (rspeed+v[i])*tb/2
    else: #???
        a = (rspeed+t[i]-lspeed)/2
        c = (2*lspeed+a)*a/2 + (lspeed+a+rspeed)*(t[i]-a)/2
    return c

ans=0
for i in range(0,n):
    ans += dist(i)

print(ans)