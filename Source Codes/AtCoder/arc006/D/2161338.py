H, W = map(int, input().split())
index = ".o".index
C = [list(map(index, input())) for i in range(H)]

# A, B, C ?????????
CNT = [12, 16, 11]

E = [[0]*W for i in range(H)]

# ????????
for j in range(W):
    tmp = 0
    for i in range(H-1, -1, -1):
        if C[i][j]:
            tmp += 1
        else:
            tmp = 0
        E[i][j] = tmp
for i in range(H):
    st = [(0, W)]
    Ei = E[i]
    a = 0; b = W
    for j in range(W-1, -1, -1):
        e = Ei[j]
        while a > e:
            st.pop()
            a, b = st[-1]
        if a < e:
            st.append((e, j))
            a = e; b = j
        Ei[j] = min(b - j + 1, a)

# ???
D = [[0]*(W+1) for i in range(H+1)]
for i in range(H):
    tmp = 0
    Dj = D[i]
    Di = D[i+1]
    for j, v in enumerate(C[i]):
        tmp += v
        Di[j+1] = tmp + Dj[j+1]
def calc(i0, j0, i1, j1):
    return D[i1+1][j1+1] - D[i1+1][j0] - D[i0][j1+1] + D[i0][j0]

index = CNT.index
ans = [0]*3
dd = [-1, -2, -3]
for i in range(H):
    Cp = C[i-1]
    Ci = C[i]
    Ei = E[i]
    for j in range(W):
        if not Ci[j] or (j and Ci[j-1]) or (i and Cp[j]) or (i and j and Cp[j-1]):
            continue
        p = Ei[j] # ??
        #if C[i-p][j+p] or (j >= 2*p and Ci[j-2*p]) or (i >= 2*p and C[i-2*p][j]):
        #    continue
        ni = i - p
        for dj in dd:
            nj = j + dj*p
            if not 0 <= ni <= H - 7*p or not 0 <= nj <= W - 7*p:
                continue
            s = calc(ni+p, nj+p, ni + 6*p-1, nj + 6*p-1)
            t = calc(ni, nj, ni+7*p-1, nj+7*p-1)
            # ???????? 0
            if s == t:
                ans[index(s // (p**2))] += 1
                break
print(*ans)