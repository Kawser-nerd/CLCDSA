N = [int(x) for x in input()]
Nd = sum(N)
for i, d in enumerate(N):
    if i == 0:
        N[i] = d-1
    else:
        N[i] = 9
N9 = sum(N)

print(max(Nd, N9))