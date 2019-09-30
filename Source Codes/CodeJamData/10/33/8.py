import math
inf = 'C-small-attempt0.in'
#inf = 'in.txt'
f_in = open(inf)
f_out = open('out.txt', 'w')
dic = {'0':[0,0,0,0],'1':[0,0,0,1],'2':[0,0,1,0],'3':[0,0,1,1],'4':[0,1,0,0],
'5':[0,1,0,1],'6':[0,1,1,0],'7':[0,1,1,1],'8':[1,0,0,0],'9':[1,0,0,1],'A':[1,0,1,0],'B':[1,0,1,1],'C':[1,1,0,0],'D':[1,1,0,1],'E':[1,1,1,0],'F':[1,1,1,1]}

def to_bin_list(s):
    ans = []
    for l in s:
        ans += dic[l]
    return ans

def find_max(board, i, j, m, n):
    color = board[i][j]
    side = 1
    while True:
        if i + side == m  or j + side == n :
            return side
        for k in xrange(side + 1):
            if board[i+side][j + k] != (color + side + k) % 2 or board[i+k][j + side] != (color + side + k) % 2 or board[i+side][j + k] == -1 or board[i+k][j + side] == -1:
                return side
        if i + side == m -1 or j + side == n - 1:
            return side + 1
        side += 1


def cros_out(board,m,n):
    max_size = -1
    cord = (-1, -1,-1,-1)
    for i in xrange(m):
        for j in xrange(n):
            if board[i][j] != -1:
                side = find_max(board, i, j, m, n)
                if side > max_size:
                    max_size = side
                    cord = (i, j, i + side - 1, j + side - 1)
    return cord

def slove(case):
    lin = f_in.next().split(' ')
    m = int(lin[0])
    n = int(lin[1])
    dict = {}
    board = [to_bin_list(f_in.next()[:-1]) for j in xrange(m)]
    while True:
        cord = cros_out(board,m,n)
        if cord == (-1,-1,-1,-1):
            break
        for x1 in xrange(cord[0], cord[2] + 1):
                            for y1 in xrange(cord[1], cord[3] + 1):
                                board[x1][y1] = -1
        side = cord[2] - cord[0] + 1
        try:
           dict[side] += 1
        except:
            dict[side] = 1
    print >>f_out, ''.join(['Case #', str(case),': ', str(len(dict))])
    ls = [str(t) +' '+str(dict[t]) for t in dict]
    ls = ls[::-1]
    for l in ls:
        print >>f_out, l

T = int(f_in.next())
for case in xrange(1, T + 1):
    slove(case)


f_out.close()
f_in.close()