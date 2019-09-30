R, C, K = map(int, input().split())
P = [[0 for c in range(C)] for r in range(R)]
Black = []
for r in range(R):
    s = input()
    Indexes = [c for c, x in enumerate(s) if x == "x"]
    for c in Indexes:
        Black.append((r, c))
    Indexes.append(C)
    low, high = -1, 0 
    for c in range(C):
        if c < Indexes[high]:
            P[r][c] = min(c-low, Indexes[high] - c)
        elif c == Indexes[high]:
            low = Indexes[high]
            high += 1

ans = (R+2-2*K)*(C+2-2*K)

if len(Black) >= ans/(2*K):
    for c in range(K-1, C-K+1):
        for r in range(K-1, R-K+1):
            for k in range(0, K):
                    if min(P[r+k][c], P[r-k][c]) < K-k:
                        ans -= 1
                        break
else:
    Search = []
    for r in range(-K+1, K):
        for c in range(-K+1, K):
            if 0 <= abs(r) + abs(c) < K:
                Search.append((r, c))
    Board = [[0 for c in range(C)] for r in range(R)]
    for b in Black:
        for s in Search:
            if K-1 <= b[0]+s[0] <= R-K and K-1 <= b[1]+s[1] <= C-K:
                if Board[b[0]+s[0]][b[1]+s[1]] == 0:
                    Board[b[0]+s[0]][b[1]+s[1]] = 1
                    ans -= 1

print(ans)