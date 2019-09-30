N=int(input())
L=[list(map(int,input().split())) for _ in range(N-1)]

for i in range(N-1):
    tmp=0
    for j in range(i,N-1):
        c,s,f=L[j]
        if tmp<=s:
            tmp=s+c
        else:
            if (tmp-s)%f==0:
                tmp+=c
            else:
                tmp+=f-(tmp-s)%f+c
    print(tmp)

print(0)