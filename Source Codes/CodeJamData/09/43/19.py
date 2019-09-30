#-*-coding:utf-8-*-

import sys

fh=open(sys.argv[1])
T = int(fh.readline())

def crosses(k, line1, line2):
    #print(line1, line2)
    for i in range(k - 1):
        u0 = line1[i]
        u1 = line1[i+1]
        v0 = line2[i]
        v1 = line2[i+1]
        if ((u0 < v0) != (u1 < v1)) or ( u0 == v0 ) or ( u1 == v1):#:# and (u0 != v0 and u1 != v0): 
            #print("Cross at {4}: {0},{1} - {2},{3}".format(u0, u1, v0, v1, i))
            return True
        pass
    return False

current_minimum = None
def count_minimum_clusters(n, pos, matrix, current_clusters, assigned):
    global current_minimum
    if pos == n:
        #print(assigned)
        if current_minimum is None or current_clusters < current_minimum:
            current_minimum = current_clusters
            pass
        return current_clusters
    if current_minimum is not None and current_clusters >= current_minimum:
        return current_clusters
    line = matrix[pos]
    minimum_clusters = None
    for c in range(current_clusters + 1):
        crossed = False
        for i in range(pos):
            cl = assigned[i]
            if cl == c and line[i]:
                #print('{0} and {1} crosses, cannot use {2} for {3}'.format(pos, i, c, pos))
                crossed = True
                break
            pass
        if not crossed:
            assigned[pos] = c
            clusters = count_minimum_clusters(n, pos + 1, matrix, current_clusters, assigned)
            if minimum_clusters is None or clusters < minimum_clusters:
                minimum_clusters = clusters
                pass
            pass
        pass
    if pos > 0:
        #print('assign ', (current_clusters + 1), pos)
        assigned[pos] = current_clusters + 1
        clusters = count_minimum_clusters(n, pos + 1, matrix, current_clusters + 1, assigned)
        if minimum_clusters is None or clusters < minimum_clusters:
            minimum_clusters = clusters
            pass
        pass
    return minimum_clusters


for cn in range(1, T+1):
    n, k = map(int,fh.readline().split(' '))
    lines = []
    for i in range(n):
        values = map(int, fh.readline().split(' '))
        lines.append(values)
        pass
    matrix = [[False] * n for i in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j] = matrix[j][i] = crosses(k, lines[i], lines[j])
            pass
        pass
    #print(matrix)
    current_minimum = None
    print( 'Case #{0}: {1}'.format(cn, count_minimum_clusters(n, 0, matrix, 0, [None] * n) + 1))
    pass
