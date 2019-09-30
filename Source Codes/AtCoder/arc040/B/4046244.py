N,R=map(int,input().split())

S=list(input())
Last=0
for i in range(N):
    if S[N-1-i]==".":
        Last=N-1-i
        break
if S.count(".")==0:
    print(0)
    exit()
elif Last-(R-1)<=0:
    print(1)
    exit()
else:
    Shot=0
    for i in range(N):
        if S.count(".")==0:
            break
        elif S[i]==".":
            Shot+=1
            for j in range(i,i+R):
                if j>N-1:
                    pass
                else:
                    S[j]="o"
    print(Shot+Last-(R-1))