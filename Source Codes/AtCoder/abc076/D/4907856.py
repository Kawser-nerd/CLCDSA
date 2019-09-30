n = int(input())
ts = [int(item)*2 for item in input().split()]
vs = [int(item) for item in input().split()]

time = sum(ts) + 1
speed_l = [0] * time
speed_r = [0] * time 

t_id = 0
speed = 0
ts_copy = ts[:]
# Forward
for i in range(time+1):
    ts_copy[t_id] -= 1
    speed_l[i] = speed
    if speed >= vs[t_id]:
        speed = vs[t_id]
    else:
        speed += 0.5 

    if ts_copy[t_id] == 0:
        if t_id + 1 >= n:
            break
        t_id += 1

# Backward
speed = 0
for i in range(time-1, -1, -1):
    ts[t_id] -= 1
    speed_r[i] = min(speed, speed_l[i])
    if speed >= vs[t_id]:
        speed = vs[t_id]
    else:
        speed += 0.5 

    if ts[t_id] == 0:
        if t_id <= 0:
            break
        t_id -= 1

print(sum(speed_r) / 2.0)