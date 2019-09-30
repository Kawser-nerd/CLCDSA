from itertools import product

def check(Qss):
    if max(map(sum, Qss)) > 1:
        return False
    if max(map(sum, zip(*Qss))) > 1:
        return False
    if max(map(sum, zip(*[[0]*i + Qs + [0]*(7-i) for i, Qs in enumerate(Qss)]))) > 1:
        return False
    if max(map(sum, zip(*[[0]*(7-i) + Qs + [0]*i for i, Qs in enumerate(Qss)]))) > 1:
        return False
    return True


css = [input() for _ in range(8)]
Qss = [[1 if c == 'Q' else 0 for c in cs] for cs in css]
rows = [r for r in range(8) if sum(Qss[r]) == 0]

for columns in product(range(8), repeat=5):
    for r, c in zip(rows, columns):
        Qss[r][c] = 1
    if check(Qss):
        print('\n'.join([''.join(['Q' if Q else '.' for Q in Qs]) for Qs in Qss]))
        break
    for r, c in zip(rows, columns):
        Qss[r][c] = 0
else:
    print('No Answer')