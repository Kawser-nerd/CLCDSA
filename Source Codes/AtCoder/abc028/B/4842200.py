S = input()

d = {}
for s in S:
    d[s] = d.get(s, 0) + 1

print(d.get('A', 0), d.get('B', 0), d.get('C', 0), d.get('D', 0), d.get('E', 0), d.get('F', 0))