H,W = (int(x) for x in input().split())
fig = [['#' for x in range(W+2)]]
org = [['.' for x in range(W+2)] for y in range(H+2)]
area = [[-1,-1],[-1,0],[-1,1],
        [0,-1],[0,1],
        [1,-1],[1,0],[1,1]]
pos = True

for i in range(H):
    S = list(input())
    fig.append(['#'] + S + ['#'])

fig += [['#' for x in range(W+2)]]

for i in range(1,H+1):
    for j in range(1,W+1):
        if fig[i][j] == '#':
            if all((fig[i+k[0]][j+k[1]] == '#' for k in area)):
                org[i][j] = '#'
            else:
                org[i][j] = '?'

for i in range(1,H+1):
    for j in range(1,W+1):
        if org[i][j] == '?':
            if all((org[i+k[0]][j+k[1]] != '#' for k in area)):
                pos = False
                break
            org[i][j] = '.'
    else:
        continue
    break

if pos:
    print('possible')
    for i in range(1,H+1):
        for j in range(1,W+1):
            print(org[i][j], end='')
        print()
else:
    print('impossible')