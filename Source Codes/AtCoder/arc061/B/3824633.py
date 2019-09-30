import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000)

H, W, N = (int(i) for i in input().split())
if N == 0:
    reslis = [0] * 10
    reslis[0] = (H-2)*(W-2) - sum(reslis)
else:
    L = []
    for k in range(N):
        a, b = (int(i) for i in input().split())
        for i in range(3):
            for j in range(3):
                if 1 <= a - 2 + i <= H - 2 and 1 <= b - 2 + j <= W - 2:
                    L.append((a-2 + i, b-2 + j))
    L.sort()
    temp = None
    cc = 1
    reslis = [0] * 10
    for se in L:
        if temp == se:
            cc += 1
        else:
            if temp == None:
                pass
            else:
                reslis[cc] += 1
                cc = 1
            temp = se
    reslis[cc] += 1

    reslis[0] = (H-2)*(W-2) - sum(reslis)

for i in reslis:
    print(i)