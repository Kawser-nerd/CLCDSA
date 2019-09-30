t = int(input())
for tc in range(t):
    print("Case #%d:"%(tc+1), end = " ")
    n, c, m = map(int, input().split())
    cust = [0] * c
    seats = [0] * n
    #l = []
    for _ in range(m):
        pos, buy = map(int, input().split())
        seats[pos-1] += 1
        cust[buy-1] += 1
        #l.append((pos-1, buy-1))
    #l.sort()
    cseats = list(seats)
    for j in range(1, len(cseats)):
        cseats[j] += cseats[j-1]
    #print(seats,cseats)
    z = max(max(cust), max((cseats[j] + j) // (j + 1) for j in range(len(cseats))))
    print(z, sum(max(seats[j]-z, 0) for j in range(len(seats))))

