N = int(input())

min_count = 10**10

for i in range(1,N):
    A = i
    B = N-i
    count = 0
    for a in str(A):
        count += int(a)
    for b in str(B):
        count += int(b)
    min_count = min(min_count, count)

print(min_count)