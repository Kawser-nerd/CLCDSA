N = int(input())
temp = [0] * 6

for _ in range(N):
    max_tmp, min_tmp = map(float, input().split())
    if max_tmp >= 35:
        temp[0] += 1
    elif 30 <= max_tmp < 35:
        temp[1] += 1
    elif 25 <= max_tmp < 30:
        temp[2] += 1
    if min_tmp >= 25:
        temp[3] += 1
    elif max_tmp < 0:
        temp[5] += 1
    if min_tmp < 0 and 0 <= max_tmp:
        temp[4] += 1

print(*temp)