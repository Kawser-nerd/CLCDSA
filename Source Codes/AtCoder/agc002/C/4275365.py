N, L = map(int, input().split())
A = list(map(int, input().split()))
pre = A[0]
index = -1
for i in range(1, N):
    if pre + A[i] >= L:
        index = i
        break
    pre = A[i]

if index == -1:
    print("Impossible")
else:
    print("Possible")
    i = 1
    while i < index:
        print(i)
        i += 1
    i = N - 1
    while index - 1 < i:
        print(i)
        i -= 1