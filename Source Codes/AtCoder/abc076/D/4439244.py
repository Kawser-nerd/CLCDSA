N = int(input())
ts = list(map(int, input().split()))
vs = list(map(int, input().split()))

maxv = [0] # vel=0 at initial
for v,t in zip(vs,ts):
    maxv[-1] = min(maxv[-1], v)
    for ti in range(t*2):
        maxv.append(v)
maxv[-1] = 0 # vel=0 at last
T = len(maxv)
# print(T)

for i in range(T-1):
    maxv[i+1] = min(maxv[i+1], maxv[i]+0.5)

for i in reversed(range(T-1)):
    maxv[i] = min(maxv[i], maxv[i+1]+0.5)
    
ans = 0
for i in range(T-1):
    ans += (maxv[i] + maxv[i+1])/4
print(ans)