from collections import deque

H,W = map(int,input().split())
_input = []
sy,sx = 0,0
gy,gx = 0,0
for i in range(H):
    row = list(map(str,input().split()))
    if 's' in row[0] or 'g' in row[0]:
        for j in range(W):
            if row[0][j] == 's':
                sy,sx = i,j
            if row[0][j] == 'g':
                gy,gx = i,j

    _input.append(list(row[0]))

#print(_input)
#print(sy,sx)
#print(gy,gx)

#?????q1??????q2?
q1 = deque([(sy,sx)])
q2 = deque([])

dyx=((1,0),(-1,0),(0,1),(0,-1))

#?????????????????????????
counted_map = [[-1]*W for _ in range(H)]
counted_map[sy][sx] = 0

#??????'g'?'.'?
_input[gy][gx] = '.'

while q1 or q2:
    #????????
    if len(q1) != 0:
        y,x = q1.popleft()
    else:  
        y,x = q2.popleft()
    
    now_count = counted_map[y][x]

    if (y,x) == (gy,gx):
        counted_map[y][x] = now_count
        break

    for dy,dx in dyx:
        ny = y + dy
        nx = x + dx

        if ny < 0 or nx < 0 or ny >= H or nx >= W:
            continue

        # ?????????
        if _input[ny][nx] == '.' and counted_map[ny][nx] == -1:
            counted_map[ny][nx] = now_count
            q1.append((ny,nx))
        
        if _input[ny][nx] == '#' and counted_map[ny][nx] == -1:
            counted_map[ny][nx] = now_count + 1
            q2.append((ny,nx))

'''
for i in counted_map:
    print(i)
'''

print('YES' if counted_map[gy][gx] <= 2 else 'NO')