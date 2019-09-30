N, W = map(int, input().split())
vs = [[] for _ in range(4)]
w1, v1 = map(int, input().split())
vs[0].append(v1)
for i in range(N - 1):
    w, v = map(int, input().split())
    vs[w - w1].append(v)
#print(vs)
s = [[0] for _ in range(4)]
for i in range(4):
    vs[i].sort()
    for j in range(len(vs[i])):
        s[i].append(s[i][-1] + vs[i][-j-1])
#print(vs)
ans = 0
for i in range(N + 1):
    if i > len(vs[0]):
        break
    if i * w1 > W:
        break
    si = s[0][i]
    for j in range(N + 1 - i):
        if j > len(vs[1]):
            break
        if i * w1 + j * (w1 + 1) > W:
            break
        sj = si
        sj += s[1][j]
        for k in range(N + 1 - i - j):
            if k > len(vs[2]):
                break
            if i * w1 + j * (w1 + 1) + k * (w1 + 2) > W:
                break
            sk = sj
            sk += s[2][k]
            for l in range(N + 1 - i - j - k):
                if l > len(vs[3]):
                    break
                if i * w1 + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3) > W:
                    break
                sl = sk
                sl += s[3][l]
                ans = max(ans, sl)
print(ans)