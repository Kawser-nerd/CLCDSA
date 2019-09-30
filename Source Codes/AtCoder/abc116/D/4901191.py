num_lines, max_num = map(int, input().split())

inp_sorted = [[int(st) for st in input().split()] for _ in range(num_lines)]
# print(inp_sorted)
inp_sorted.sort(key=lambda x: x[1], reverse=True)

inp_map = {}
for t, d in inp_sorted:
    if not t in inp_map:
        inp_map[t] = d

variety = set()
score = 0

dup = []
for i in range(max_num):
    t, d = inp_sorted[i]
    if t in variety:
        dup.append((t,d))
    variety.add(t)
    if t in inp_map:
        del inp_map[t]
    score += d

var_value = len(variety)
max_score = score + var_value*var_value

for t, d in sorted(inp_map.items(), key=lambda x: x[1], reverse=True):
    if (len(dup)):
        t2, d2 = dup.pop()
        var_value += 1
        score = score - d2 + d
        max_score = max(max_score, score + var_value*var_value)

print(max_score)