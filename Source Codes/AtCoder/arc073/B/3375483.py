N, W = map(int, input().split())
recW = [[] for i in range(4)]
W0, W1, W2, W3 = 0, 0, 0, 0
for i in range(N):
    w, v = map(int, input().split())
    if i == 0:
        recW[0].append((w, v))
        W0, W1, W2, W3 = w, w + 1, w + 2, w + 3
    elif w == W0:
        recW[0].append((w, v))
    elif w == W0 + 1:
        recW[1].append((w, v))
    elif w == W0 + 2:
        recW[2].append((w, v))
    else:
        recW[3].append((w, v))

for i in range(4):
    recW[i] = sorted(recW[i], reverse=True)


a, b, c, d = len(recW[0]), len(recW[1]), len(recW[2]), len(recW[3])
recV0 = [0] * (a + 1)
for i in range(1, a + 1):
    recV0[i] = recV0[i - 1] + recW[0][i - 1][1]

recV1 = [0] * (b + 1)
for i in range(1, b + 1):
    recV1[i] = recV1[i - 1] + recW[1][i - 1][1]

recV2 = [0] * (c + 1)
for i in range(1, c + 1):
    recV2[i] = recV2[i - 1] + recW[2][i - 1][1]

recV3 = [0] * (d + 1)
for i in range(1, d + 1):
    recV3[i] = recV3[i - 1] + recW[3][i - 1][1]


num = 0
for i in range(a + 1):
    for j in range(b + 1):
        for k in range(c + 1):
            for l in range(d + 1):
                tmpW = W0 * i + W1 * j + W2 * k + W3 * l
                if tmpW > W:
                    continue
                else:
                    num = max(num, recV0[i] + recV1[j] + recV2[k] + recV3[l])

print(num)