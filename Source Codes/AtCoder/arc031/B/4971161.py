island = [input() for i in range(10)]

# ??
m = [[1,0], [-1,0], [0,1], [0,-1]]

# ????????
for i in range(10):
    for j in range(10):
        island2 = [island[k] for k in range(10)]
        if island2[i][j] == 'x':
            island2[i] = island2[i][:j]+'o'+island2[i][j+1:]
            # ??????????
            flag = False
            count = 0
            stack = []
            for i2 in range(10):
                for j2 in range(10):
                    if island2[i2][j2] == 'o':
                        count +=1
                        if count >1:
                            flag = True
                        if flag:
                            break
                        stack.append([i2,j2])
                        while stack:
                            p = stack.pop()
                            island2[p[0]] = island2[p[0]][:p[1]]+'x'+island2[p[0]][p[1]+1:]
                            for k2 in range(len(m)):
                                if 0<=p[0]+m[k2][0]<10 and 0<=p[1]+m[k2][1]<10 and island2[p[0]+m[k2][0]][p[1]+m[k2][1]] == 'o':
                                    stack.append([p[0]+m[k2][0], p[1]+m[k2][1]])
                if flag:
                    break
            if count == 1:
                print('YES')
                exit()

print('NO')