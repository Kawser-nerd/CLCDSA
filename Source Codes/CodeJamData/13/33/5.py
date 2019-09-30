import collections
import copy

T = int(raw_input())
for t in range(T):
    N = int(raw_input())
    attacks = collections.defaultdict(list)
    height = collections.defaultdict(int)
    for i in range(N):
        d, n, w, e, s, delta_d, delta_p, delta_s = [int(x) for x in raw_input().split()]
        for k in range(n):
            day = d + k * delta_d
            west = w + k * delta_p
            east = e + k * delta_p
            strength = s + k * delta_s
            attacks[day].append((west, east, strength))
    days = sorted(attacks.keys())
    res = 0
    for day in days:
        new_height = copy.copy(height)
        for attack in attacks[day]:
            was_successful = False
            west, east, strength = attack
            for pos in range(west, east):
                if strength > height[pos]:
                    was_successful = True
                    new_height[pos] = max(strength, new_height[pos])
            if was_successful:
                res += 1
        height = new_height
    print 'Case #%d: %d' % (t + 1, res)
