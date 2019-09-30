import sys
N, L = map(int, input().split())
a = [(-1, 0), (0, 1)] + [(int(x), 0 if d == "R" else 1) for x, d in (l.split() for l in sys.stdin)] + [(L+1, 0), (L+2, 1)]

jumps = 0
l_rabbit, r_rabbit, l_mid, r_mid = 0, 0, 0, 0

for (current_pos, current_dir), (next_pos, next_dir) in zip(a, a[1:]):
    if current_dir == 0:
        l_rabbit += 1
        if current_dir == next_dir:
            jumps += (next_pos - current_pos - 1) * l_rabbit
        else:
            l_mid, r_mid = current_pos, next_pos
    else:
        jumps += current_pos - r_mid - r_rabbit
        r_rabbit += 1
        if current_dir != next_dir:
            jumps += max(l_rabbit, r_rabbit) * (r_mid - l_mid - 1)
            l_rabbit, r_rabbit = 0, 0

print(jumps)