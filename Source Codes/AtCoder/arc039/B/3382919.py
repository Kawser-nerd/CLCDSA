n,k = map(int, input().split())
if k < n:
    ans = 1
    for i in range(k):
        ans *= (n+k-1-i)
        ans //= (i+1)
    print(ans%1000000007)
    quit()

else:
    list = []
    for i in range(1,k+1):
        list.append(i*n)
    if k in list:
        print(1)
        quit()
    else:
        d = k//n
        k -= d*n
        ans = 1
        for i in range(k):
            ans *= (n-i)
            ans //= (i+1)
        print(ans%1000000007)