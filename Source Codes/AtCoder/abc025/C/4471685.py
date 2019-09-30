# encoding: utf-8
sumbc = 0
b = []
for i in range(2):
    vals = map(int, input().split())
    for val in vals:
        b.append(val)
        sumbc += val
c = []
for i in range(3):
    vals = map(int, input().split())
    for val in vals:
        c.append(val)
        sumbc += val

memo = [None] * (3 ** 9)
        
def idx(field): return sum([vi * (3 ** i) for i, vi in enumerate(field)])

def play(turn, field):
    idx_tmp = idx(field)
    if memo[idx_tmp] != None: return memo[idx_tmp]
    # print("#", turn, field)
    if turn >= 9:
        ret = 0
        for i in range(2):
            for j in range(3):
                if field[3 * i + j] == field[3 * (i + 1) + j]:
                    ret += b[3 * i + j]
                else:
                    ret -= b[3 * i + j]
        for i in range(3):
            for j in range(2):
                if field[3 * i + j] == field[3 * i + (j + 1)]:
                    ret += c[2 * i + j]
                else:
                    ret -= c[2 * i + j]
    else:
        rets = []
        for i in range(9):
            if field[i] > 0: continue
            if turn % 2:
                field_tmp = list(field)
                field_tmp[i] = 2
                rets.append(play(turn + 1, field_tmp))
            else:
                field_tmp = list(field)
                field_tmp[i] = 1
                rets.append(play(turn + 1, field_tmp))
        else:
            if turn % 2: ret = min(rets)
            else: ret = max(rets)
    if memo[idx_tmp] == None: memo[idx_tmp] = ret
    return ret

diff = play(0, [0] * 9)
print((sumbc + diff) // 2)
print((sumbc - diff) // 2)