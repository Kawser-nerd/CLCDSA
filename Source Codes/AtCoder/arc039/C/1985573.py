K = int(input())
S = input()
dxdys = {'R': (1, 0), 'L': (-1, 0), 'U': (0, 1), 'D': (0, -1)}
inv = {'R': 'L', 'L': 'R', 'U': 'D', 'D': 'U'}
x, y = 0, 0
boundary = {(0, 0): {'R': (0, 0), 'L': (0, 0), 'U': (0, 0), 'D': (0, 0)}}
for i in range(K):
    c = S[i]
    nx, ny = boundary[(x, y)][c]
    nx += dxdys[c][0]
    ny += dxdys[c][1]
    boundary[(nx, ny)] = {'R': (nx, ny), 'L': (nx, ny), 'U': (nx, ny), 'D': (nx, ny)}
    for cc in dxdys:
        nnx = nx + dxdys[cc][0]
        nny = ny + dxdys[cc][1]
        if (nnx, nny) in boundary:
            boundary[(nx, ny)][cc] = boundary[(nnx, nny)][cc]
            boundary[boundary[(nx, ny)][inv[cc]]][cc] = boundary[(nx, ny)][cc]
            boundary[boundary[(nx, ny)][cc]][inv[cc]] = boundary[(nx, ny)][inv[cc]]
    x, y = nx, ny
print(x, y)