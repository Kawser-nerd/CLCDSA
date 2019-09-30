def task():
    ac, aj = map(int, input().split())
    times = []
    used = [0, 0]
    for i in range(ac):
        c, d = map(int, input().split())
        times.append((c, 1, 0))
        times.append((d, 0, 0))
        used[0] += d - c
    for i in range(aj):
        c, d = map(int, input().split())
        times.append((c, 1, 1))
        times.append((d, 0, 1))
        used[1] += d - c
    times = sorted(times)
    last_time, last_is_start, last_who = times[-1]
    last_time -= 24 * 60
    wiggle_room = 0
    needed_edges = 0
    elim = []
    for (time, is_start, who) in times:
        if is_start:
            if who != last_who:
                wiggle_room += time - last_time
                needed_edges += 1
            else:
                elim.append((time - last_time, who))
        last_time, last_is_start, last_who = time, is_start, who
    #print(times)
    #print(used, needed_edges, wiggle_room, elim)
    elim = sorted(elim)
    for length, who in elim:
        if length + used[who] <= 720:
            used[who] += length
        else:
            needed_edges += 2
    return needed_edges

t = int(input())
for i in range(t):
    print("Case #{}: {}".format(i+1, task()))
