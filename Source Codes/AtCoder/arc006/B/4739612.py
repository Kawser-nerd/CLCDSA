N,L = map(int,input().split())
m = [i for i in range(N)]
for _ in range(L):
    s = input()
    for i,y in enumerate(s[1:2*N:2]):
        if y == '-':m[i],m[i+1] = m[i+1],m[i]
if N == 1:print(1)
else:print(m[input().index('o') // 2]+1)