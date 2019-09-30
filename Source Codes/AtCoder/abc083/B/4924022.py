N, A, B = [int(i) for i in input().split()]
total = 0
for i in range(1, N+1):
    sum = 0
    for j in str(i):
        sum += int(j)
    if A <= sum <= B:
        total += i
print(total)