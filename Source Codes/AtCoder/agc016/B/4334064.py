n = int(input())

a = list(map(int,input().split()))
a_max = max(a)
a_min = min(a)
if a_max > a_min+1:
    print('No')
    exit()
k = a_max
if a_max == a_min:
    if k == n-1 or 2*k <= n:
        print('Yes')
    else:
        print('No')
else:
    uni = a.count(k-1)
    if k >= uni + 1 and k <= uni + (n-uni)//2:
        print('Yes')
    else:
        print('No')