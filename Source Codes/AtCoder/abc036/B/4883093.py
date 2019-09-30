N=int(input())
s=[list(input()) for i in range(N)]
for i in range(N):
    t=""
    for j in range(N):
        t+=s[N-1-j][i]
    print(t)