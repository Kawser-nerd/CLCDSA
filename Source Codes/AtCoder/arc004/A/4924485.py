N=int(input())
M=[0]*N
for i in range(N):
    M[i]=list(map(int,input().split()))

D=0
for i in range(N-1):
    for j in range(i+1,N):
        a=M[i]
        b=M[j]
        d=((a[0]-b[0])**2+(a[1]-b[1])**2)**(1/2)
        if d>D:
            D=d
        else:
            continue
print(D)