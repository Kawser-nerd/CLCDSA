import itertools
N = int(input())
C = input()
R = ["A", "B", "X", "Y"]
num = float('inf')
for a, b in itertools.product(R, R):
    L = a + b
    for c, d in itertools.product(R, R):
        P = c + d
        i = 0
        tmp = 0
        while i < N:
            # if i + 1 < N:
                # print(C[i] + C[i + 1])
            if i + 1 < N and (C[i] + C[i + 1] == L or C[i] + C[i + 1] == P):
                i += 2
                tmp += 1
            else:
                i += 1
                tmp += 1

        num = min(num, tmp)

print(num)