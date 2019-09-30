r, g, b = map(int, input().split())

def get_moves(left, num, base):
    if left <= base <= left + num - 1:
        return (base - left) * (base - left + 1) // 2 + (left + num - 1 - base) * (left + num - 1 - base + 1) // 2
    elif base < left:
        return (left + num - 1 - base) * (left + num - 1 - base + 1) // 2 - (left - base - 1) * (left - base - 1 + 1) // 2
    else:
        return (base - left) * (base - left + 1) // 2 - (base - (left + num)) * (base - (left + num) + 1) // 2

r_pos = g_pos = b_pos = 0

min_moves = 10 ** 100

for g_pos in range(-500, 501):
    if (r - 1) // 2 - 100 < g_pos:
        r_pos = - ((r - 1) // 2) - 100
    else:
        r_pos = g_pos - r
    
    if - ((b - 1) // 2) + 100 > g_pos + g:
        b_pos = - ((b - 1) // 2) + 100
    else:
        b_pos = g_pos + g

    moves = 0
    moves += get_moves(r_pos, r, -100)
    moves += get_moves(g_pos, g, 0)
    moves += get_moves(b_pos, b, 100)

    if moves < min_moves:
        min_moves = moves

print(min_moves)