n = int(input())
A = [input() for _ in range(n)]
A_t = [''] * n
for c in A:
    for i in range(n):
        A_t[i] += c[i]

def checkTable(shift):
    for i in range(n):
        if A_t[(i + shift) % n] != A[i][shift:] + A[i][:shift]:
            return False
    return True

count = 0
for i in range(n):
    if checkTable(i):
        count += 1
print(count * n)