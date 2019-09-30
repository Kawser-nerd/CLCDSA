from collections import Counter
N = int(input())
A = list(map(int,input().split()))
ctr = Counter(A)

if len(ctr) >= 3:
    print('No')
    exit()
if len(ctr) == 1:
    k,v = list(ctr.items())[0]
    if k == 1:
        print('Yes')
    elif N <= k:
        print('No')
    elif N >= 2*k:
        print('Yes')
    else:
        print('Yes' if k==N-1 else 'No')

else:
    (k1,v1),(k2,v2) = list(sorted(ctr.items()))
    if k2-k1 != 1 or k2 >= N:
        print('No')
    elif v1 > k1:
        print('No')
    else:
        print('Yes' if v2//2 + v1 >= k2 else 'No')