N = int(input())
A = list(map(int, input().split()))

# even is +
now = 0
even_count = 0
for i, a in enumerate(A):
    now += a
    if i % 2 == 0 and now <= 0:
        even_count += 1 - now
        now = 1
    elif i % 2 == 1 and now >= 0:
        even_count += abs(-1 - now)
        now = -1

# odd is +
now = 0
odd_count = 0
for i, a in enumerate(A):
    now += a
    if i % 2 == 0 and now >= 0:
        odd_count += abs(-1 - now)
        now = -1
    elif i % 2 == 1 and now <= 0:
        odd_count += 1 - now
        now = 1
print(min(even_count, odd_count))