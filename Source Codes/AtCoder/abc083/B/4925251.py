N, A, B = [int(m) for m in input().split()]
total = 0
for num in range(1, N + 1):
    sum = 0
    for kurai in str(num):
        sum += int(kurai)
    if A <= sum <= B:
        total += num
print(total)