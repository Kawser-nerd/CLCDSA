from collections import deque
n = int(input())
board = [0]*n
edge = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
q = deque()
q.append((0,1))
q.append((-1,-1))
while q:
    from_, color = q.popleft()
    if board[from_] != 0:
        continue
    board[from_] = color
    for i in edge[from_]:
        q.append((i,color))
if sum(board) > 0:
    print("Fennec")
else:
    print("Snuke")