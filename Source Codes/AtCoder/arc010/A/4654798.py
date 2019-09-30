N,M,A,B = map(int,input().split())
res = N
c = []
for _ in range(M):
    c.append(int(input()))
for i in range(M):
    if res <= A:res += B
    if res < c[i]:
        print(i+1)
        break
    else:res -= c[i]
else:print('complete')