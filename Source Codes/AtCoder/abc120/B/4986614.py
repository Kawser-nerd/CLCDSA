A,B,K = map(int, input().split())

n = min(A, B)
count = 0
for i in range(n, 0, -1):
    if i == 0:
        break
    if A%i == 0 and B%i == 0:
        count = count + 1
        if count == K:
            break
print(i)