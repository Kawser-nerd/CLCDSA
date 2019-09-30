def main():
    T = input()
    for t in range(1, T+1):
        print "Case #%d:" % t
        R, C = map(int, raw_input().split())
        lovers = map(int, raw_input().split())
        lover = {}

        v = []
        for i in range(R+1): v.append(['']*(C+1))

        for i in range(0, len(lovers), 2):
            lover[lovers[i]] = lovers[i+1]
            lover[lovers[i+1]] = lovers[i]

        N = (R+C)*2
        pos = {}

        for i in range(1, C+1):
            pos[i] = (1, i, 1)
        for i in range(C+1, C+R+1):
            pos[i] = (i-C, C, 2)
        for i in range(C+R+1, C+R+C+1):
            pos[i] = (R, (C+R+C+1)-i, 3)
        for i in range(C+R+C+1, C+R+C+R+1):
            pos[i] = ((C+R+C+R+1)-i, 1, 4)

        def check(cs):

#            if cs == 1:
#                import pdb; pdb.set_trace()

            visit = {}

            for i in range(1, N+1):
                x, y, p = pos[i]

                if (x, y, p) in visit:
                    if visit[(x,y,p)] in (i, lover[i]):
                        continue
                    else:
                        return False

                visit[(x, y, p)] = i
                q = [pos[i]]

                def vis(nx, ny, np, v1, v2):
                    if not (1 <= nx <= R):
                        return False
                    if not (1 <= ny <= C):
                        return False
                    if (nx, ny, np) not in visit:
                        q.append((nx, ny, np))
                        visit[(nx, ny, np)] = v1
                        return False
                    elif visit[(nx, ny, np)] not in (v1, v2):
                        return True

                while q:
                    xx, yy, pp = q.pop()
                    if pp == 1:
                        if vis(xx-1, yy, 3, i, lover[i]): return False
                        if v[xx][yy] == '/':
                            if vis(xx, yy, 4, i, lover[i]): return False
                        else:
                            if vis(xx, yy, 2, i, lover[i]): return False

                    if pp == 2:
                        if vis(xx, yy+1, 4, i, lover[i]): return False
                        if v[xx][yy] == '/':
                            if vis(xx, yy, 3, i, lover[i]): return False
                        else:
                            if vis(xx, yy, 1, i, lover[i]): return False

                    if pp == 3:
                        if vis(xx+1, yy, 1, i, lover[i]): return False
                        if v[xx][yy] == '/':
                            if vis(xx, yy, 2, i, lover[i]): return False
                        else:
                            if vis(xx, yy, 4, i, lover[i]): return False

                    if pp == 4:
                        if vis(xx, yy-1, 2, i, lover[i]): return False
                        if v[xx][yy] == '/':
                            if vis(xx, yy, 1, i, lover[i]): return False
                        else:
                            if vis(xx, yy, 3, i, lover[i]): return False

            return True

        for cs in range(0, 1<<(R*C)):
            n = 1
            for i in range(1, R+1):
                for j in range(1, C+1):
                    if (cs & n) > 0:
                        v[i][j] = '/'
                    else:
                        v[i][j] = '\\'

                    n <<= 1

            if check(cs):
                for i in range(1, R+1):
                    print ''.join(v[i])
                break

        else:
            print "IMPOSSIBLE"

main()
