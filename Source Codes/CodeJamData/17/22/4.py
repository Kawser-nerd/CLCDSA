def solve(n, r, o, y, g, b, v):
    assert n == r+o+y+g+b+v

    # print('r', r, 'o', o, 'y', y, 'g', g, 'b', b, 'v', v)

    if g > r or v > y or o > b: return 'IMPOSSIBLE'

    if g == r and g > 0:
        if v == y == o == b == 0:
            return 'GR' * g
        return 'IMPOSSIBLE'

    if v == y and v > 0:
        if g == r == o == b == 0:
            return 'VY' * v
        return 'IMPOSSIBLE'

    if o == b and o > 0:
        if g == r == v == y == 0:
            return 'OB' * o
        return 'IMPOSSIBLE'
    

    def mix(wrap_ch, wrap_count, inside_ch, inside_count):
        if inside_count == 0: return [wrap_ch] * wrap_count
        ret = [(wrap_ch + inside_ch) * (inside_count) + wrap_ch]
        return ret + [wrap_ch] * (wrap_count - inside_count - 1)

    R = mix('R', r, 'G', g)
    B = mix('B', b, 'O', o)
    Y = mix('Y', y, 'V', v)

    # print('R', R)
    # print('B', B)
    # print('Y', Y)

    p, q, r = sorted((R, B, Y), key=len)

    if len(p) + len(q) < len(r):
        return 'IMPOSSIBLE'
    slots = [[] for i in range(len(r))]
    for i in range(len(p)):
        slots[i].append(p[i])
    for i in range(len(q)):
        slots[-1-i].append(q[i])

    fragments = []
    for i in range(len(r)):
        fragments.append(r[i])
        assert slots[i]
        fragments.append(''.join(slots[i]))
    return ''.join(fragments)

cases = int(input())
for cc in range(cases):
    print('Case #%d: %s' % (cc+1, solve(*map(int, input().split()))))
