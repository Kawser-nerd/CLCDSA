N = int(input())
A = list(map(int, input().split()))
bf = [-1 for i in range(10**5+1)]
bfn = 0
ans = 1
for i in range(N):
    if bf[A[i]] == -1:
        bf[A[i]] = i
        ans = max(ans, i-bfn+1)
    else:
        if(bfn == 0):
            ans = max(ans, i-bf[A[i]])
            bfn = bf[A[i]] + 1
            bf[A[i]] = i
        else:
            if(bfn > bf[A[i]]):
                ans = max(ans, i-bfn+1)
                bf[A[i]] = i
            elif bfn == bf[A[i]]:
                ans = max(ans, i-bfn)
                bfn = bf[A[i]] + 1
                bf[A[i]] = i
            else:
                ans = max(ans, i-bf[A[i]])
                bfn = bf[A[i]] + 1
                bf[A[i]] = i
 
print(ans)