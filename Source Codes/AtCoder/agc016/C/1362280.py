H,W,h,w = [int(x) for x in input().split(' ')]
if W % w != 0:
    r = W % w
    n = int(W/w)
    n = n+1
    print('Yes')
    for i in range(H):
        for k in range(W):
            if (k+1) % w == 0:
                print(-n*(w-1) - 1, end = '')
            else:
                print(n, end = '')
            if k == W-1:
                print()
            else:
                print(end = ' ')
elif H % h != 0:
    r = H % h
    n = int(H/h)
    n = n + 1
    print('Yes')
    store = 0
    for i in range(H):
        if (i+1) % h == 0:
            store = -n*(h-1) - 1
        else:
            store = n
        for k in range(W):
            if k == W-1:
                print(store)
            else:
                print(store, end=' ')
else:
    print('No')