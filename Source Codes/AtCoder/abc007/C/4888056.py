from collections import deque

def isIn(max_row, max_col, row, col):
    if row >= 0 and row < max_row and col >= 0 and col < max_col:
        return True
    else:
        return False

r, c = map(int, input().split())
start = list(map(int, input().split()))
goal = list(map(int, input().split()))
start[0] -= 1
start[1] -= 1
goal[0] -= 1
goal[1] -= 1
maze = []
visit = [[float('inf')]*c for _ in range(r)]

for _ in range(r):
    maze.append(list(input()))

qu = deque([[start[0], start[1]]])
visit[start[0]][start[1]] = 0

while qu:

    now = qu.popleft()
 
    right = [now[0], now[1] + 1]
    left = [now[0], now[1] - 1]
    up = [now[0] - 1, now[1]]
    down = [now[0] + 1, now[1]]
    
    if (isIn(r, c, right[0], right[1]) and maze[right[0]][right[1]] != '#' and visit[now[0]][now[1]] + 1 < visit[right[0]][right[1]]):
        visit[right[0]][right[1]] = visit[now[0]][now[1]] + 1
        qu.append(right)
    if (isIn(r, c, left[0], left[1]) and maze[left[0]][left[1]] != '#' and visit[now[0]][now[1]] + 1 < visit[left[0]][left[1]]):
        visit[left[0]][left[1]] = visit[now[0]][now[1]] + 1
        qu.append(left)
    if (isIn(r, c, up[0], up[1]) and maze[up[0]][up[1]] != '#' and visit[now[0]][now[1]] + 1 < visit[up[0]][up[1]]):
        visit[up[0]][up[1]] = visit[now[0]][now[1]] + 1
        qu.append(up)
    if (isIn(r, c, down[0], down[1]) and maze[down[0]][down[1]] != '#' and visit[now[0]][now[1]] + 1 < visit[down[0]][down[1]]):
        visit[down[0]][down[1]] = visit[now[0]][now[1]] + 1
        qu.append(down)
print(visit[goal[0]][goal[1]])