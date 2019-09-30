N = int(input())
s = "".join([input() for _ in [0]*N])

result = 0
for d in range(N):
    result += all(c1 == c2 for y in range(N-1) for c1, c2 in zip(s[y*N+y+1:y*N+N], s[(y+1)*N+y::N]))
    s = s[-N:] + s[:-N]

print(result*N)