def findcycles(path, depth):
    currv = path[-1]
    for nextv in range(N):
        if adjacent[currv][nextv]:
            if nextv in path:
                cycle = path[path.index(nextv):]
                if len(cycle) > 2:
                    cycles.append(cycle)
                continue
            findcycles(path + [nextv], depth + 1)

def colour(colours):  # colours is list of current choices
    global numcolours
    if len(colours) == N:
        #check validity
        for cycle in cycles:
            currcolours = [colours[v] for v in cycle]
            for c in range(numcolours):
                if c not in currcolours:
                    return []
        return colours
    for c in range(numcolours):
        colouring = colour(colours + [c])
        if colouring:
            return colouring
    return []

T = int(input())

for t in range(T):
    N, M = [int(i) for i in input().split()]
    U = [int(i) for i in input().split()]
    V = [int(i) for i in input().split()]
    adjacent = [[(abs(i - j) == 1) for i in range(N)] for j in range(N)]
    adjacent[0][N-1] = True
    adjacent[N-1][0] = True
    for m in range(M):
        adjacent[U[m]-1][V[m]-1] = True
        adjacent[V[m]-1][U[m]-1] = True
    #print("\n".join([" ".join([str(int(c)) for c in row]) for row in adjacent]))
    cycles = []
    findcycles([0], 0)
    #print(cycles)
    smallestcycle = min([len(cycle) for cycle in cycles])
    numcolours = smallestcycle
    colouring = colour([0])
    while not colouring:
        numcolours -= 1
        colouring = colour([0])
    print("Case #{}: {}".format(t+1, numcolours))
    print(" ".join([str(i+1) for i in colouring]))