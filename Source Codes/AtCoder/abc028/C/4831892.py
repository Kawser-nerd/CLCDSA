A = list(map(int, input().split()))
l = []
for i in range(5):
    for j in range(i + 1, 5):
        for k in range(j + 1, 5):
            l.append(A[i] + A[j] + A[k])

l.sort()

print(l[-3])