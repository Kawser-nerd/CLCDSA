K = int(input())
s = input()
unit = 400001
center = 200000
current_pos = center * unit + center
d = {current_pos: [current_pos + unit, current_pos + 1, current_pos - unit, current_pos - 1]}

_dir = {"U": 0, "R": 1, "D": 2, "L": 3}
for c in s:
    dir1, dir2 = _dir[c], (_dir[c]+2)%4
    opposite = d[current_pos][dir2]
    next_pos = d[current_pos][dir1]
    while next_pos in d:
        d[next_pos][dir2] = opposite
        next_pos = d[next_pos][dir1]
    d[next_pos] = [next_pos+unit, next_pos+1, next_pos-unit, next_pos-1]
    d[next_pos][dir2] = opposite
    d[current_pos][dir1] = d[next_pos][dir1]

    current_pos = next_pos

print(current_pos%unit-center, current_pos//unit-center)