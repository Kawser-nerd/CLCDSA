N = int(input())
A = list(map(int, input().split()))

total = 1
trend = 0
prev = A[0]
for a in A[1:]:
    if a > prev and trend < 0:
        total += 1
        trend = 0
    elif a < prev and trend > 0:
        total += 1
        trend = 0
    elif trend == 0:
        trend = a - prev
    prev = a

print(total)