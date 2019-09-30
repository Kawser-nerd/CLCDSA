N = int(input())
csf = []
t = 0
for _ in range(N - 1):
    csf.append(list(map(int, input().split())))
# print(csf)
for i in range(N - 1):
    t = 0
    for j in range(i, N - 1):
        if t < csf[j][1]:
            t = csf[j][1]
        if t % csf[j][2] == 0:
            t += csf[j][0]
        else:
            t += csf[j][2] - t % csf[j][2]
            t += csf[j][0]
    print(t)
print(0)