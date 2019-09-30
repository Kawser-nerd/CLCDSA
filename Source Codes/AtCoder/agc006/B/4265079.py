N,X = map(int,input().split())
if N == 1:
    print('Yes')
    print(1)
    exit()

if X == 1 or X == 2*N-1:
    print('No')
    exit()
print('Yes')

if N == X:
    ans = list(range(1,2*N))
elif N > X:
    k = N-X
    ans = list(range(2*N-k,2*N)) + list(range(1,2*N-k))
else:
    k = X-N
    ans = list(range(k+1,2*N)) + list(range(1,k+1))

print(*ans, sep='\n')