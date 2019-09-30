S = input()
given = ['dream', 'dreamer', 'erase', 'eraser']


while True:
    if len(S) == 0:
        break
    judge = [S.endswith(i) for i in given]
    if True in judge:
        index = judge.index(True)
        length = len(given[index])
        S = S[:-length]
    else:
        print('NO')
        quit()

print('YES')