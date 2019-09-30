Q = int(input())
for q in range(Q):
    N = int(input())
    d = {}
    for i in range(2*N-1):
        x = map(int,(input().split()))
        for num in x:
            d[num] = d.get(num, 0) + 1
    
    res = []
    for key in d:
        if d[key] % 2 == 1:
            res.append(key)

    res.sort()
    for i in range(len(res) ):
        res[i] = str(res[i])

    print("Case #{}: {}".format(q+1," ".join(res)))