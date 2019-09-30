def cost(a, b, n, N):
    d = b - a
    return n * d * (N + N - d + 1) // 2

def solve(num):
    N, M = map(int, input().split())
    MaxSum = 0
    MinSum = 0
    Events = []
    for i in range(M):
        start, end, count = map(int, input().split())
        MaxSum += cost(start, end, count, N)
        Events.append([start, 0, count])
        Events.append([end, 1, count])
    Curr = []
    Events.sort()
    for x, typ, count in Events:
        if typ == 0:
            Curr.append([x, count])
        else:
            Curr.sort()
            while count > 0:
                if Curr[-1][1] <= count:
                    MinSum += cost(Curr[-1][0], x, Curr[-1][1], N)
                    count -= Curr[-1][1]
                    Curr.pop()
                else:
                    MinSum += cost(Curr[-1][0], x, count, N)
                    Curr[-1][1] -= count
                    count = 0
    print("Case #", num, ": ", (MaxSum - MinSum) % 1000002013, sep='')

T = int(input())
for num in range(1, T + 1):
    solve(num)

