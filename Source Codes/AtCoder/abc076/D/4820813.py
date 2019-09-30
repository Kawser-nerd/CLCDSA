N = int(input())
T = [int(i) for i in input().split()]
V = [int(i) for i in input().split()]

maxv = [0]
for t, v in zip(T, V):
    maxv[-1] = min(maxv[-1], v)
    for i in range(t * 2):
        maxv.append(v)
maxv[-1] = 0

for i in range(len(maxv) - 1):
    maxv[i + 1] = min(maxv[i + 1], maxv[i] + 0.5) 
    
for i in reversed(range(len(maxv) - 1)):
    maxv[i] = min(maxv[i], maxv[i + 1] + 0.5)
    
ans = 0
for i in range(len(maxv) - 1):
    ans += (maxv[i] + maxv[i + 1]) * 0.5 / 2
    
print(ans)