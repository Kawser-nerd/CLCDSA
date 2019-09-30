n = int(input())
L = [2,1]
for i in range(100):
    L.append(L[-1]+L[-2])
print(L[n])