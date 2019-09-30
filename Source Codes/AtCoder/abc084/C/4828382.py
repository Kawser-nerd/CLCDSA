n = int(input())
csf = [[int(item) for item in input().split()] for _ in range(n-1)]

for i in range(n):
    total_time = 0
    for c, s, f in csf[i:]:
        time = 0
        # wait for start
        if total_time < s:
            time += s - total_time
        # wait for next train
        else:
            time += (f - total_time % f) % f
        # take train
        time += c
        total_time += time
    print(total_time)