N = int(input())
W = [input() for _ in range(N)]
last = W.pop(0)
words = set([last])
win = ['WIN', 'LOSE']
i_win = 0
for w in W:
    if w in words or last[-1] != w[0]:
        print(win[i_win])
        exit()
    else:
        words.add(w)
        last = w
        i_win = 1 - i_win
print('DRAW')