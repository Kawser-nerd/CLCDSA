N, K = map(int, input().split())
A = [int(input()) for i in range(N)]
ans = 0
cont = 0
i = 1
while i != N:
    if cont < K-2:
        if A[i] > A[i-1]:
            cont += 1
        else:
            cont = 0
    else:
        if A[i] > A[i-1]:
            #print(i)
            ans += 1
        else:
            cont = 0
    i += 1
if K == 1:
    print(N)
    quit()
print(ans)