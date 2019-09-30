def convert(m, e=False):
    if m % 5 == 0: return m
    else:
        if e: return m + (5 - m % 5)
        else: return m - (m % 5)

blocks = [False] * 12 * 24
n = int(input())
for _ in range(n):
    s, e = map(int, input().split('-'))
    sb = int(s/100)*12 + int(convert(s % 100) / 5)
    eb = int(e/100)*12 + int(convert(e % 100, True) / 5)
    for a in range(sb, eb):
        blocks[a] = True
pb = False
for i, e in enumerate(blocks):
    if pb == False and e == True:
        print('%02d%02d-'%(i/12, 5*(i%12)), end='')
    elif pb == True and e == False:
        print('%02d%02d'%(i/12, 5*(i%12)))
    elif e == True and i == len(blocks)-1:
        print('2400')
    pb = e