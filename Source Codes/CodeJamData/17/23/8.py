import heapq
INF = 10 ** 20
N = 0

# first pass: run dijkstra on graph for every city
def graph(D, s):
    queue = [(0, s)]
    dist = [INF] * N
    dist[s] = 0
    
    while len(queue) > 0:
        cost, pos = heapq.heappop(queue)
        fromPos_d = dist[pos]
        
        for nb in xrange(N):
            if D[pos][nb] < 0:
                continue
            
            consider = dist[pos] + D[pos][nb]            
            if dist[nb] > consider:
                dist[nb] = consider
                heapq.heappush(queue, (consider, nb))

    return dist

# second pass: run dijkstra on horses for every query
def horse(H, E, S, s, t):
    queue = [(0, s)]
    dist = [INF] * N
    dist[s] = 0
    
    while len(queue) > 0:
        cost, pos = heapq.heappop(queue)
        fromPos_d = dist[pos]
        
        for nb in xrange(N):
            if H[pos][nb] > E[pos]:
                continue
            
            consider = dist[pos] + float(H[pos][nb]) / S[pos]
            if dist[nb] > consider:
                dist[nb] = consider
                heapq.heappush(queue, (consider, nb))

    return dist[t]

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N, Q = map(int,IN.readline().split())
    
    E = [0] * N
    S = [0] * N
    for i in xrange(N):
        E[i], S[i] = map(int,IN.readline().split())
    
    D = []
    for i in xrange(N):
        D.append(map(int,IN.readline().split()))
    
    U = [0] * Q
    V = [0] * Q
    for i in xrange(Q):
        U[i], V[i] = map(int,IN.readline().split())
        
    
    H = []
    for i in xrange(N):
        H.append(graph(D, i))
    
    answer = [0] * Q
    for q in xrange(Q):
        answer[q] = str(horse(H, E, S, U[q]-1, V[q]-1))
    answer = ' '.join(answer)
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
