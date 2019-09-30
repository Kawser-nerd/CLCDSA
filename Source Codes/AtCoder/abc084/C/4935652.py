N = int(input())

min_time = [0 for _ in range(N)]
for i in range(N-1):
    speed, start, interval = map(int, input().split())
    min_time[i] += start + speed
    for j in range(i):
        if min_time[j] - start < 0:
            min_time[j] = start
        else:
            while (min_time[j] - start) % interval != 0:
                min_time[j] += 1
        min_time[j] += speed

for ans in min_time:
    print(ans)