N, T = map(int, input().split())
ts = list(map(int, input().split()))

total = 0
for i in range(1, len(ts)):
    if ts[i] - ts[i-1] >= T:
        total += T
    else:
        total += ts[i] - ts[i-1]
total += T

print(total)