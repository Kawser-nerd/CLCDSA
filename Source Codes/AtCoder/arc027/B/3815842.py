N = int(input())
S1 = input()
S2 = input()

firsts = [S1[0], S2[0]]
d = dict()

for a, b in zip(S1, S2):
    if a not in d:
        d[a] = set()
    d[a].add(b)
    if b not in d:
        d[b] = set()
    d[b].add(a)

def remove_node(n):
    if n in d:
        l = d[n]
        del d[n]
        for v in l:
            remove_node(v)

for k in "0123456789":
    remove_node(k)

m = 1
while d:
    d_i = list(d.keys())[0]
    m *= (10 - (d_i in firsts))
    remove_node(d_i)

print(m)