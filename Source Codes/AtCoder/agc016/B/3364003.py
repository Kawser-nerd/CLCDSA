N = int( input())
A = list( map( int, input().split()))
K = max(A)
L = min(A)
if K == L:
    if K == N-1 or 2*K <= N:
        print('Yes')
    else:
        print('No')
elif abs(K-L) == 1:
    x = K*N - sum(A)
    if 2*K - x <= N and x < K:
        print('Yes')
    else:
        print('No')
else:
    print('No')