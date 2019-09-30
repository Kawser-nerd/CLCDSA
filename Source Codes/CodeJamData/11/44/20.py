
from heapq import *
INF=1000000

def solve(xxx):
    #print "Case %s" % (xxx)
    (p,w) = map(int, raw_input().split())
    wa = []
    for i in range(p):
        wa.append([])

    for (a,b) in map(lambda x: map(int, x.split(',')), raw_input().split()):
        wa[a].append(b)
        wa[b].append(a)    

    dist = []
    seen = set()
    prev = []
    for i in range(p):
        dist.append(INF)
        prev.append([])
    dist[0] = 0

    #print "wa=%s" % wa
    #print "dist=%s" % dist
    while(len(dist) > 0):
        #print "dist=%s" % dist
        u = fmin(dist, seen)
        if u == None:
            break

        seen.add(u)
        for v in wa[u]:
            alt = dist[u] + 1
            if alt <= dist[v]:
                if alt < dist[v]:
                    prev[v] = []
                dist[v] = alt
                prev[v].append(u)

    conq = dist[1]-1
    threaten = 0
    for u in prev[1]:
        tmp_threaten = max_threaten(wa, prev, u, set())
        threaten = max(tmp_threaten, threaten)
    print "Case #%s: %s %s" % (xxx, conq, threaten-conq-1)
    
def max_threaten(wa, prev, u, seen):
#    print "max_t u=%s, seen=%s" %(u, seen)
    my_threaten = 0
    for v in wa[u]:
        if not v in seen:
#            print v
            my_threaten = my_threaten + 1
            seen.add(v)
    #self
    if not u in seen:
        my_threaten = my_threaten + 1
        seen.add(u)
        
#    print "u=%s my=%s"%(u,my_threaten)

#    print "u=%s prev=%s"%(u, prev[u])
    prev_threaten = 0
    for v in prev[u]:
        v_threaten = max_threaten(wa, prev, v, seen.copy())
        prev_threaten = max(prev_threaten, v_threaten)
#    print "u=%s ret==%s"%(u, my_threaten + prev_threaten)
    return my_threaten + prev_threaten

def fmin(dist,seen):
    m = INF
    ix = None
    for i in range(len(dist)):
        if i in seen:
            continue
        if dist[i] < m:
            m = dist[i]
            ix = i
    return ix
        

def main():
    t = int(raw_input())
    for i in range(t):
        solve(i+1)

main()
