N = int(input())

L = [2, 1]
for i in range(2, N+2):
    L.append(L[i-1]+L[i-2])
print(L[N])