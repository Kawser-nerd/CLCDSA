H,W = (int(x) for x in input().split())
s = []
for i in range(H):
    s += [ ['.'] + list(input()) + ['.'] ]
s = [['.' for i in range(W+2)]] + s + [['.' for i in range(W+2)]]

around = [[-1,0],[0,-1],[0,1],[1,0]]
clear = True
for i in range(1,H+1):
    for j in range(1,W+1):
        if s[i][j] == '#':
            if all((s[i+k[0]][j+k[1]] == '.' for k in around)):
                clear = False
                break
    else:
        continue
    break

if clear:
    print('Yes')
else:
    print('No')