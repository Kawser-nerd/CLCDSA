N, C = map(int, input().split())
xs = []
vs = []
for i in range(N):
    x, v = map(int, input().split())
    xs += [x]
    vs += [v]

costOAs = [0] + xs
costOBs = [0] + [C - x for x in reversed(xs)]

# ??????A?????????
accV = 0
eneOAs = [0] * (N + 1)
maxOAs = [0] * (N + 1)
for A, v in enumerate(vs, 1):
    accV += v
    eneOAs[A] = accV - costOAs[A] # ?????????
    maxOAs[A] = max(maxOAs[A - 1], eneOAs[A])

# ???????B?????????
accV = 0
eneOBs = [0] * (N + 1)
maxOBs = [0] * (N + 1)
for B, v in enumerate(reversed(vs), 1):
    accV += v
    eneOBs[B] = accV - costOBs[B] # ?????????
    maxOBs[B] = max(maxOBs[B - 1], eneOBs[B])

# O?B(?O?A)
ans = 0
for B in range(N + 1):
    ene = eneOBs[B] + max(0, -costOBs[B] + maxOAs[N - B])
    ans = max(ans, ene)

# O?A(?O?B)
for A in range(N + 1):
    ene = eneOAs[A] + max(0, -costOAs[A] + maxOBs[N - A])
    ans = max(ans, ene)

print(ans)