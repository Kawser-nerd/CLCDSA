n = int(input())
a = list(map(int, input().split()))
seq = []

for i in range(0, n + 1):
    b = [None] * n
    for j in range(0, n): b[j] = a[j]
    seq = []
    for j in range(i - 2, -1, -1):
        seq.append((j + 1, j))
        seq.append((j + 1, j))
        b[j] += b[j + 1] * 2
    for j in range(i, n - 1):
        seq.append((j, j + 1))
        seq.append((j, j + 1))
        b[j + 1] += b[j] * 2
    valid = True
    for j in range(n - 1):
        if b[j] > b[j + 1]:
            valid = False
            break
    if valid: break

print(len(seq))
print('\n'.join(map(lambda x: '%d %d' % (x[0] + 1, x[1] + 1), seq)))