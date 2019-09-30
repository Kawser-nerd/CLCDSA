N=int(input())
A=list(map(int,input().split()))
now=0
cnt=0
one=sum(A)//N
if sum(A)%N!=0:print(-1)
else:
    for a in A:
        now+=a-one
        if now!=0:
            cnt+=1
    print(cnt)