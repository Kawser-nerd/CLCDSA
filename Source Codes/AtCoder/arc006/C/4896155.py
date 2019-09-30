n = int(input())
L = [0]
for i in range(n):
    box = int(input())
    if (L[-1] >= box) and (L[-1] > 0):
        for j in range(len(L) - 1, -1, -1):
            if L[j] < box:
                L[j + 1] = box
                break
    else:
        L.append(box)
print(len(L) - 1)