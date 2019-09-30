t = int(input())


for tc in range(1, t + 1):
    print("Case #" + str(tc) + ": ", end = "")
    n, k = map(int, input().split())
    d = {n: 1}
    lastc = None
    while k > 0:
        c = max(d)
        lastc = c
        d[(c - 1)//2] = d.get((c - 1)//2, 0) + d[c]
        d[c//2] = d.get(c//2, 0) + d[c]
        k -= d[c]
        del d[c]
    print(lastc // 2, (lastc - 1) // 2)


    
