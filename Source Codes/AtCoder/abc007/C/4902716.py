from collections import deque

R, C = list(map(int, input().split()))
sy, sx = list(map(int, input().split()))
gy, gx = list(map(int, input().split()))

_d = {'#':1, '.':0} # #:wall, .:coriddor
_map = [[_d[x] for x in input()] for _ in range(R)]
# map[r-1][c-1]

moves = [(0,1),(1,0),(0,-1),(-1,0)]

dq = deque([(sy, sx, 0)])
visited = set([(sy, sx)])

while dq:
    y, x, dist = dq.popleft() #First in first out
    # map[y-1][x-1]
    for m in moves:
        next_y = y + m[0]
        next_x = x + m[1]

        if next_y ==gy and next_x==gx:
            print(dist+1)
            break

        if (next_y,next_x) not in visited:
            if _map[next_y-1][next_x-1]==0:
                dq.append((next_y,next_x, dist+1))
                visited.add((next_y,next_x))
    else:
        continue
    break
else:
    print('Something wrong')