N=int(input().strip())
maze=[]
for _ in range(2):
    maze.append(list(map(int, input().split())))
ans=0

for i in range(N):
    ans=max(ans,sum(maze[0][:i+1])+sum(maze[1][i:]))
print(ans)