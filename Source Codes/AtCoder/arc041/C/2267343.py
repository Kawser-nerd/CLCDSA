N, l = map(int, input().split())
L = []; R = []; mode = 0
prev = 1
def calc(L, R):
    if not R:
        med = l - L[-1]
    elif not L:
        med = R[0] - 1
    else:
        med = R[0] - 1 - L[-1]
    S = len(L); T = len(R)
    Ld = -S*(S-1)//2
    for i in range(S-2, -1, -1):
        Ld += L[-1] - L[i]
    Rd = -T*(T-1)//2
    for i in range(1, T):
        Rd += R[i] - R[0]
    return Ld + Rd + med * max(S, T)

ans = 0
for i in range(N):
    x, d = input().split()
    x = int(x)
    if mode == 0:
        if d == 'R':
            L.append(x)
        else:
            R.append(x)
            mode = 1
    else:
        if d == 'L':
            R.append(x)
        else:
            ans += calc(L, R)
            L = [x]; R = []
            mode = 0
ans += calc(L, R)
print(ans)