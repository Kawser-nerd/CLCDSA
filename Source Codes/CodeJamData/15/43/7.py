import networkx as nx
data = iter(open('C-large.in').read().splitlines())
cases = int(next(data))

def build_graph(sentances):
    g = nx.DiGraph()
    for num, sentence in enumerate(sentences):
        for i in range(len(sentence)):
            g.add_edge((sentence[i], 'i'), (sentence[i], 'o'), capacity=1)
            if num == 0:
                g.add_edge('en', (sentence[i], 'i'), capacity=1)
                g.add_edge((sentence[i], 'o'), 'en', capacity=1)
            elif num == 1:
                g.add_edge('fr', (sentence[i], 'i'), capacity=1)
                g.add_edge((sentence[i], 'o'), 'fr', capacity=1)
            if num < 2:
                continue
            for j in range(i):
                g.add_edge((sentence[i], 'o'), (sentence[j], 'i'), capacity=1)
                g.add_edge((sentence[j], 'o'), (sentence[i], 'i'), capacity=1)
    return g

for case in range(1, cases + 1):
    N = int(next(data))
    sentences = [next(data).split() for _ in range(N)]
    g = build_graph(sentences)
    ans = nx.maximum_flow(g, 'fr', 'en')[0]
    print "Case #%d: %d" % (case, ans)

