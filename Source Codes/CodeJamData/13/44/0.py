#!/usr/bin/env python3
import sys

def splitf():
    return [int(x) for x in sys.stdin.readline().split()]

def gcd(a, b):
    if b:
        return gcd(b, a % b)
    else:
        return a

def inverse(a, m):
    a %= m
    assert a != 0
    if a == 1:
        return 1
    else:
        return ((1 - m * inverse(m, a)) // a) % m

def solve_min(b, m, s, t):
    assert 0 <= s and s <= t and t < m
    b %= m
    if b == 0 or s == 0:
        return 0
    elif b * 2 > m:
        return solve_min(m - b, m, m - t, m - s)
    else:
        # Can't necessarily set y = ceil(floor(a*s/m) * m/a), because it might
        # be less than s. So treat y = s as a special case
        best = (b * s) % m

        zs = b * s // m + 1
        zt = b * t // m
        if (zs <= zt):
            best = min(best, solve_min(-m, b, zs, zt))
        return best

# Finds smallest non-negative x such that mod(a * x, m) lies in the range [s, t],
# or -1 if there are no solutions.
# Preconditions:
# - 0 <= a
# - 0 <= s <= t < m.
#
def first_hit(a, m, s, t):
    assert 0 <= s and s <= t and t < m
    # Remove any common factors
    a %= m
    g = gcd(a, m)
    a = a // g
    m = m // g
    s = (s + g - 1) // g
    t = t // g

    if s == 0:
        return 0
    elif (a == 0 or s > t):
        return -1
    else:
        b = inverse(a, m)
        # ax mod m = y <=> x mod m = by
        return solve_min(b, m, s, t)

class Team:
    def __init__(self, sz, vel, x):
        self.sz = sz
        self.vel = vel
        self.x = x
        self.score = -1

def canon(a, H):
    a = a % (2 * H)
    if a >= H:
        return 2 * H - a
    else:
        return a

def distance(a, b, H):
    return abs(canon(a, H) - canon(b, H))

def unsafe_ranges(D, cover, H):
    ans = []
    H2 = 2 * H
    if D <= H:
        if D > cover:
            w = (D - cover - 1) // 2
            ans.append((-w, H - D + w))
    else:
        tmp = unsafe_ranges(2 * H - D, cover, H)
        for (a, b) in tmp:
            ans.append((-b, -a))
    return ans

def is_unsafe(ranges, pos, H):
    pos = pos % H
    for r in ranges:
        if pos >= r[0] and pos <= r[1]:
            return True
        if pos - H >= r[0] and pos - H <= r[1]:
            return True
    return False

(cases,) = splitf()
for cas in range(cases):
    (A, B) = splitf()
    (N, M) = splitf()
    (V, W) = splitf()
    teams = [Team(N, V, 0), Team(M, W, B)]
    (Y, X, VY, VX) = splitf()
    if VX != 0:
        for team in teams:
            vx = abs(VX)
            H = A * vx
            H2 = 2 * H

            x0 = X
            if VX * (team.x - X) < 0:
                x0 = 2 * (B - team.x) - x0
            pos = (abs(x0 - team.x) * VY + Y * vx) % H2
            D = 2 * B * VY % H2
            cover = 2 * B * team.sz * team.vel
            it = 0
            seen = set()
            ranges = unsafe_ranges(D * team.sz % H2, cover, H)
            nranges = []
            for i in range(len(ranges)):
                r = ranges[i]
                r = (r[0] - pos, r[1] - pos)
                for h in range(-5 * H, 5 * H, H):
                    if r[0] >= h and r[0] < h + H:
                        e = min(r[1], h + H - 1)
                        nranges.append((r[0] - h, e - h))
                        nranges.append((r[0] - h + H, e - h + H))
                        r = (e + 1, r[1])
                        if r[0] > r[1]:
                            break

            first = -1
            for r in nranges:
                f = first_hit(D, 2 * H, r[0], r[1])
                if f != -1 and (first == -1 or f < first):
                    first = f
            if first != -1:
                team.score = first + team.sz

    if teams[0].score == -1 and teams[1].score == -1:
        result = 'DRAW'
    elif teams[0].score == -1:
        result = 'LEFT'
    elif teams[1].score == -1:
        result = 'RIGHT'
    elif teams[0].score == teams[1].score:
        if VX > 0:
            result = 'LEFT'
        else:
            result = 'RIGHT'
    elif teams[0].score < teams[1].score:
        result = 'RIGHT'
    else:
        result = 'LEFT'

    if result == 'LEFT':
        result = 'LEFT {}'.format(teams[1].score)
    elif result == 'RIGHT':
        result = 'RIGHT {}'.format(teams[0].score)

    print('Case #{}:'.format(cas + 1), result)
