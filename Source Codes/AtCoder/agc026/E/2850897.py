from itertools import accumulate


def search_ab(sss, cursor):
    # print('a', cursor)
    ai = aaa.index(cursor)
    tmp_cur = bbb[ai]
    max_cur = sss.index(0, cursor)
    repeat = 1
    while tmp_cur < max_cur:
        cur = s.find('a', tmp_cur, max_cur)
        if cur == -1:
            break
        ai = aaa.index(cur, ai)
        tmp_cur = bbb[ai]
        repeat += 1
    return repeat, max_cur + 1


def search_ba(sss, cursor):
    # print('b', cursor)
    first_bi = bbb.index(cursor)
    max_cursor = sss.index(0, cursor)
    last_bi = aaa.index(max_cursor)

    tmp_buf = [''] * (last_bi - first_bi + 1) * 2
    tmp_max = ''
    for i in range(last_bi, first_bi - 1, -1):
        tmp_buf[aaa[i] - cursor] = 'a'
        tmp_buf[bbb[i] - cursor] = 'b'
        tmp = ''.join(tmp_buf)
        if tmp > tmp_max:
            tmp_max = tmp
    return tmp_max, max_cursor + 1


def integrate(parts_b):
    tmp_max = ''
    for pb in reversed(parts_b):
        tmp = pb + tmp_max
        if tmp > tmp_max:
            tmp_max = tmp
    return tmp_max


n = int(input())
s = input()

n2 = n * 2
sss = []
aaa, bbb = [], []
for i, c in enumerate(s):
    if c == 'a':
        aaa.append(i)
        sss.append(-1)
    else:
        bbb.append(i)
        sss.append(1)
sss = list(accumulate(sss))
repeats_a = []
parts_b = []
last_b_cur = 0
cursor = 0
while cursor < n2:
    c = sss[cursor]
    if c < 0:
        repeat, cursor = search_ab(sss, cursor)
        repeats_a.append((cursor, repeat))
    else:
        tmp, cursor = search_ba(sss, cursor)
        parts_b.append(tmp)
        last_b_cur = cursor
print(integrate(parts_b) + 'ab' * sum(r for c, r in repeats_a if c > last_b_cur))