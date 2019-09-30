from itertools import product

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
tmpH = -1
tmpW = -1
flag = True

for i, j in product(range(H), range(W)):
    if A[i][j] == "#":
        if i < tmpH or j < tmpW:
            flag = False
            break
        else:
            tmpH = i
            tmpW = j

print("Possible" if flag else "Impossible")