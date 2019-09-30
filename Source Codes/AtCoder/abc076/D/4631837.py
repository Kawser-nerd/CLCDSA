n = int(input())
time = list(map(int, input().split()))
speed = list(map(int, input().split()))
speed = [0] + speed + [0]
cumtime = [0] * (n+1)
for i in range(n):
    cumtime[i+1] = cumtime[i] + time[i]
dis = 0.0
prev = 0
l = cumtime[n]
tp = 1
for t in range(1, l+1):
    if t > cumtime[tp]:
        tp += 1
    v = speed[tp]
    v = min(v, prev + 1)
    for i in range(tp):
        v = min(v, t - cumtime[i] + speed[i])
    for i in range(tp+1, n+2):
        v = min(v, cumtime[i-1] - t + speed[i])
    if v == prev and v < speed[tp]:
        dis += v + 1/4
    else:
        dis += (v + prev) / 2
    prev = v
print(dis)