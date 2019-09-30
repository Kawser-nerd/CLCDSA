import queue

R, C = map(int, input().split())
sy, sx = map(int, input().split())
sy -= 1
sx -= 1
gy, gx = map(int, input().split())
gy -= 1
gx -= 1
m = []
for i in range(R):
    m.append(input())

Done = [[0 for i in range(C)] for j in range(R)]
q = queue.Queue()

def check():
    while not q.empty():
        now = q.get()
        i = int(now[0])
        j = int(now[1])
        c = int(now[2])
        if i == gy and j == gx:
            print(c)
            exit()
        if m[i-1][j] is '.' and Done[i-1][j] == 0:
            Done[i-1][j] = 1
            q.put([i-1,j,c+1])
        if m[i][j-1] is '.' and Done[i][j-1] == 0:
            Done[i][j-1] = 1
            q.put([i,j-1,c+1])
        if m[i+1][j] is '.' and Done[i+1][j] == 0:
            Done[i+1][j] = 1
            q.put([i+1,j,c+1])
        if m[i][j+1] is '.' and Done[i][j+1] == 0:
            Done[i][j+1] = 1         
            q.put([i,j+1,c+1])

q.put([sy,sx, 0])
check()