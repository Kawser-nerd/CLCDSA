N = int(input())
L = [2, 1]
for i in range(2, 87):
    L.append(L[i-2] + L[i-1])
print(L[N])