A=list(map(int,input().split()))
K=A[0]
S=A[1]
count=0
for a in range(K+1):
    for b in range(K+1):
        c=S-a-b
        if 0<=c<=K:
            count+=1
        else:
            continue
print(count)