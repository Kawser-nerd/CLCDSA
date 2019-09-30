n = int(input())

time = [0]+list(map(int,input().split()))+[0]
v = [0] + list(map(int,input().split()))+[0]

lines = []
t = 0
lines.append((-1,0,0))
for i in range(1,n+1):
    lines.append((t,t+time[i],v[i]))
    t+=time[i]
lines.append((t,t+1,0))
def f(x):
    speed = 10**18
    for x1,x2,vv in lines:
        if x<x1:
            speed = min(speed,vv+x1-x)
        elif x>x2:
            speed = min(speed,vv+x-x2)
        else:
            speed = min(speed,vv)
    return speed
dp = [0]*(2*t)
for i in range(2*t):
    dp[i] = f(i/2)
dp.append(0)
res = 0
res = sum(dp)*2-dp[0]-dp[-1]
print(res*0.25)