def parse(inFile):
    k = inFile.getInt()
    S = inFile.readline()
    return (k, S)

def solve((k, S)):
    edges = set([])
    outdegrees = [0] * 34
    indegrees = [0] * 34
    letters = "abcdefghijklmnopqrstuvwxyz"
    extras = "oieastbg"
    for i in xrange(len(S) - 1):
        us = [letters.index(S[i])] + ([26+extras.index(S[i])] if S[i] in extras else [])
        vs = [letters.index(S[i+1])] + ([26+extras.index(S[i+1])] if S[i+1] in extras else [])
        for u in us:
            for v in vs:
                if (u,v) not in edges:
                    edges.add((u,v))
                    indegrees[u] += 1
                    outdegrees[v] += 1
    k1 = sum([outdegrees[v] - indegrees[v] for v in xrange(34) if outdegrees[v] > indegrees[v]])
    k2 = sum([indegrees[v] - outdegrees[v] for v in xrange(34) if outdegrees[v] < indegrees[v]])
    return str(len(edges)+max(k1,k2,1))

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(parse, solve, "/Users/lpebody/gcj/2012_3/d/", "D").run()

            
