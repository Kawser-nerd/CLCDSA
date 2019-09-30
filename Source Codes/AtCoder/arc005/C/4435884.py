from collections import deque
def breadth_first_search(map_,s_y,s_x,wall = ['+']):
    ques = deque()
    ques.appendleft((s_y,s_x))
    counts = []
    for _ in range(len(map_)):
        counts.append([-1] * len(map_[0]))

    while(ques):
        x_y = ques.pop()
        y = x_y[0]
        x = x_y[1]
        if counts[y][x] == -1:
            i_js = [(1,0),(-1,0),(0,1),(0,-1)]
            new_count = 100
            now_map = map_[y][x]
            goal = False
            for i_j in i_js:
                i = i_j[0]
                j = i_j[1]
                tmp = counts[y + i][x + j]
                tmp2 = map_[y + i][x + j]
                if tmp != -1:
                    if map_[y][x] == '#':
                        if new_count > tmp + 1:
                            new_count = tmp + 1
                    else:
                        if new_count > tmp:
                            new_count = tmp
                
                elif tmp2 != '+':
                    if tmp2 == '#':
                        ques.appendleft((y + i,x + j))
                    else:
                        if tmp2 == 'g':
                            goal - True
                        ques.append((y + i,x + j))
            if new_count == 100:
                new_count = 0
            if goal:
                return new_count
            counts[y][x] = new_count
            if now_map == 'g':
                return counts[y][x]
            if new_count > 2:
                return 100
        
        #for row in counts:
        #   print(row)

    
            
    return counts

#?????????????????
def make_map_data(H,W,wall = '#',make_wall = True):
    map_ = []
    if make_wall:
        map_.append([wall] * (W + 2))
        for _ in range(H):
            map_.append([wall] + list(input()) + [wall])
        map_.append([wall] * (W + 2))
    else:
        for _ in range(H):
            map_.append(list(input()))
    return map_

H, W = (int(i) for i in input().split())
map_ = make_map_data(H,W,wall = '+')
for y in range(H + 2):
    for x in range(W + 2):
        if map_[y][x] == 's':
            s_y = y
            s_x = x

a =breadth_first_search(map_,s_y,s_x)

if a == -1 or a > 2:
    print('NO')
else:
    print('YES')