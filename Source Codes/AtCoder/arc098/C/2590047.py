N,K,Q = map(int,input().split())
A = list(map(int,input().split()))

R = sorted(set(A))
ans = 10**9
for i in range(len(R)):
    temp = []
    temp2 = []
    l = 0
    for j in range(N):
        if A[j] < R[i]:
            if l >= K:
                temp += sorted(temp2)[:min(l,max(0,l - K + 1))]
            temp2 = []
            l = 0
        else:
            temp2.append(A[j])
            l += 1
    if l >= K:
        temp += sorted(temp2)[:min(l,max(0,l - K + 1))]

    if len(temp) > Q - 1:
        temp = sorted(temp)
        ans = min(ans,temp[Q - 1] - R[i])
    else:
        break
        
print(ans)