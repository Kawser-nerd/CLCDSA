A, B, K, L = map(int, input().split())
if A*L <= B:
    print(A*K)
else:
    print(min(B*((K+L-1)//L), B*(K//L)+A*(K-L*(K//L))))