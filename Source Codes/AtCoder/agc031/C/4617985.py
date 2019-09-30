import sys

N,A,B=map(int,input().split())

BIT=0
for i in range(N):
    if (1<<i) & A!=(1<<i) & B:
        BIT+=1

if BIT%2==1:
    print("YES")
else:
    print("NO")
    sys.exit()

check=[0]*(1<<N)

ANS=[]
check[A]=1
check[B]=1

def route(x,i,j):#x????????,bit i???.j ??bit???
    NOW=x
    ANS.append(NOW)
    check[NOW]=1

    for k in range(1<<j):
        for l in range(N):
            if check[NOW ^ (1<<l)]==0 and l!=i:
                NOW=NOW ^ (1<<l)
                check[NOW]=1
                ANS.append(NOW)
                break

    return NOW^(1<<i)

checkbit=[0]*N     
for i in range(N-1,-1,-1):
    for j in range(N):
        if (1<<j)&A!=(1<<j)&B and checkbit[j]==0:
            break
    A=route(A,j,i)
    checkbit[j]=1

ANS.append(B)
print(*ANS)