N = int(input())
A = sorted(list(map(int,input().split())))
B = []


mod = 10**9+7
if N % 2 == 0:
    for i in range(1,N,2):
        B.append(i)
        B.append(i)
    for i in range(N):
        if A[i] != B[i]:
            print(0)
            exit()

    print(2**(N//2) % mod)
else:
    B.append(0)
    for i in range(2,N,2):
        B.append(i)
        B.append(i)
    for i in range(N):
        if A[i] != B[i]:
            print(0)
            exit()

    print(2**((N-1)//2) % mod)