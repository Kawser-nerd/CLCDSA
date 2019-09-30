N = int(input())
ans = 0

A = list(int(input()) for i in range(N))

for i in range(N) :
    ans += A[i]//2
    if i != N-1 :
        if A[i] >= 2 :
            A[i+1] += A[i]%2
print(ans)