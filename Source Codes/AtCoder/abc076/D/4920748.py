n = int(input())
t = [int(i) for i in input().split()]
v = [int(i) for i in input().split()]

maxspeed = [0]*(n+1)
for i in range(n-1,0,-1):
    maxspeed[i] = min(v[i], v[i-1], t[i] + maxspeed[i+1])

def dist(i,first): # distance,lastspeed
    ta = v[i] - first
    tb = v[i] - maxspeed[i+1]
    if ta + tb <= t[i]:
        c = (first+v[i])*ta/2 + v[i]*(t[i]-ta-tb) + (maxspeed[i+1]+v[i])*tb/2
        lastspeed = maxspeed[i+1]
    elif maxspeed[i+1] - first > t[i]:
        c = (first + first + t[i])*t[i]/2
        lastspeed = first + t[i]
    else:
        a = (maxspeed[i+1]+t[i]-first)/2
        c = (first+first+a)*a/2 + (first+a+maxspeed[i+1])*(t[i]-a)/2
        lastspeed = maxspeed[i+1]
    return c, lastspeed


ans = 0
firstspeed = 0
for i in range(n):
    d,firstspeed = dist(i,firstspeed)
    ans += d

print(ans)