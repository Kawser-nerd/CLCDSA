N = int(input())

b_min, isequal, total = 10**10, 0, 0
for _ in range(N):
    a, b = map(int, input().split())
    total += a
    if a > b:
        if b < b_min:
            b_min = b
    elif a == b:
        isequal += 1

if isequal == N:
    print(0)
else:
    print(int(total - b_min))