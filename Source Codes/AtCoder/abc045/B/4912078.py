SA = input()
SB = input()
SC = input()

Aidx, Bidx, Cidx = 0, -1, -1
X = SA[0]
i = 0

while True:
    if X == 'a':
        Aidx += 1
        if Aidx == len(SA):
            ans = 'A'
            break
        X = SA[Aidx]
    elif X == 'b':
        Bidx += 1
        if Bidx == len(SB):
            ans = 'B'
            break
        X = SB[Bidx]
    elif X == 'c':
        Cidx += 1
        if Cidx == len(SC):
            ans = 'C'
            break
        X = SC[Cidx]


print(ans)