N = int(input())
T = [list(map(float, input().split(" "))) for _ in range(N)]

days = [0]*6
for max_t, min_t in T:
    if 35 <= max_t:
        days[0] += 1
    if 30 <= max_t < 35:
        days[1] += 1
    if 25 <= max_t < 30:
        days[2] += 1
    if 25 <= min_t:
        days[3] += 1
    if min_t < 0 and 0 <= max_t:
        days[4] += 1
    if max_t < 0:
        days[5] += 1

print(" ".join(map(str, days)))