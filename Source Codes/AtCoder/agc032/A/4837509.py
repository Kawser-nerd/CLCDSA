N=int(input())
b=list(map(int,input().split()))

ans=[]

while len(b)>0:
    r=-1
    for i in range(len(b)):
        if b[i]==i+1:
            r=i
    if r==-1:
        print(-1)
        exit()
    ans.append(r+1)
    b=b[:r]+b[r+1:]

for i in range(N):
    print(ans[-i-1])