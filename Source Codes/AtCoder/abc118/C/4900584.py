N = int(input())
A = list(map(int, input().split()))

for i in range(N-1):
    a = [A[i], A[i+1]]
    a.sort(reverse=True)
    while True:
        tmp = a[0] % a[1]
        if tmp == 0:
            A[i+1] = a[1]
            break
        a[0], a[1] = a[1], tmp

print(a[1])