import sys

sys.setrecursionlimit(3000)

def diamond_inheritance(M):
    visited = set()
    for node in M:
        if not node in visited:
            curr_visited = set()
            if visit(M, node, curr_visited):
                return True
            visited.update(curr_visited)
    return False

def visit(M, k, visited):
    for node in M[k]:
        if not node in visited:
            if visit(M, node, visited):
                return True
        else:
            return True # diamond detected
    visited.add(k)
    return False

fi = open("A.in", "r")
fo = open("A.out", "w")

T = int(fi.readline())
for t in range(T):
    N = int(fi.readline())
    M = {}
    for i in range(N):
        line = map(int, fi.readline().split())
        M[i+1] = line[1:] # M[i] is a list of classes that i inherits from
    result = diamond_inheritance(M)
    if result:
        fo.write('Case #{0}: Yes\n'.format(t+1))
    else:
        fo.write('Case #{0}: No\n'.format(t+1))
    
fi.close()
fo.close()
