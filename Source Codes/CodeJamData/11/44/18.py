def dijkstra(p, edges):
    conquer = [p+1] * p
    conquer[0] = 0
    paths = [[] for i in range(p)]
    paths[0] = [[0]]
    
    for distance in range(p):
        # Which could I have conquered by now?
        choices = filter(lambda i:conquer[i] == distance, range(p))
        #print choices
        for target in range(p):
            if conquer[target] > distance:
                # By which path (if any) could I go there?
                for choice in choices:
                    if (choice, target) in edges:
                        #print "Reachable"
                        conquer[target] = distance+1
                        for path in paths[choice]:
                            paths[target].append(path + [target])
                        #print paths[target]
            if conquer[1] <= p:
                return distance, paths[1]
    return p+1, []

def cmpaths(p, paths, edges):
    # All planets threaten themselves and their neighbours
    threaten = [set([i]) for i in range(p)]
    for (start, end) in edges:
        threaten[start].add(end)
        
    optimize = 0
    for path in paths:
        # Remove the planets threatened by the final step - it's not taken.
        #print path
        t = reduce(lambda a,b:a.union(b), map(lambda i:threaten[i], path[:-1]), set())
        #print t
        if len(t) > optimize:
            optimize = len(t)
    return optimize

def main():
    cases = int(raw_input())
    for case in range(cases):
        p, w = map(int, raw_input().split(" "))
        wormholes = raw_input().split(" ")
        edges = []
        for wormhole in wormholes:
            a, b = map(int, wormhole.split(","))
            edges.append((a, b))
            edges.append((b, a))
        
        distance, paths = dijkstra(p, edges)
        threaten = cmpaths(p, paths, edges)
        print "Case #%d: %d %d" % (case+1, distance, threaten-(len(paths[0])-1))

main()

