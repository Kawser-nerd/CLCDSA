N=int(input())
A=list(map(int,input().split()))

l = r = 0
ans = 0
X = Y = A[0]
while 1:
    if X==Y:
        ans += r-l+1
        if r < N-1:
            r += 1
            X ^= A[r]
            Y += A[r]
        else:
            break
    else:
        X ^= A[l]
        Y -= A[l]
        l += 1
 
print(ans)