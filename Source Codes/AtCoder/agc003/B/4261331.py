N = int(input())
A = list(int(input()) for i in range(N))

ans = 0
for i in range(N) :
    ans += A[i]//2
    if i != N-1 :
        if A[i+1] >= 1 :
            A[i+1] += A[i] % 2
print(ans)