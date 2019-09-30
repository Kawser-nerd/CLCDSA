pos = [(i, j) for i in range(4) for j in range(4)]
rows = [[(i, j) for i in range(4)] for j in range(4)]
cols = [[(i, j) for j in range(4)] for i in range(4)]
diags = [[(i, i) for i in range(4)]]+[[(i, 3-i) for i in range(4)]]
wins = rows+cols+diags
tnum = input()
def next_line():
    while True:
        s = raw_input()
        if len(s)>2:
            return s
for num in range(tnum):
    tbl = [next_line() for i in range(4)]
    tbl = {(i, j): tbl[i][j] for i in range(4) for j in range(4)}
    xwon = False
    ywon = False
    finished = True
    for t in wins:
        chars = set(tbl[x] for x in t)
        if chars<=set(['X', 'T']):
            xwon = True
        if chars<=set(['O', 'T']):
            ywon = True
        if '.' in chars:
            finished = False
    answer = 'Game has not completed'
    if xwon or ywon or finished:
        if xwon:
            answer = 'X won'
        elif ywon:
            answer = 'O won'
        else:
            answer = 'Draw'
    print 'Case #%d: %s'%(num+1, answer)

