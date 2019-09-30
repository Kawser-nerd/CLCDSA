N = int(input())
S = list(input())
w = [0 for i in range(N)]
e = [0 for i in range(N)]

if S[0] == 'W':
    w[0] = 1

for i in range(1,N-1):
    if S[i] == 'W':
        w[i] = w[i-1] + 1
        e[i+1] = e[i]  
    else:
        w[i] = w[i-1]
        e[i+1] = e[i] - 1

if S[-1] == 'W':
    w[-1] = w[-2] + 1
    scale = -e[-1]
else:
    w[-1] = w[-2]
    scale = -e[-1] +1

ans = w[0] + e[0]
for i in range(N):
    w[i] = w[i] + e[i]
    if ans > w[i]:
        ans = w[i]

print(ans + scale - 1)