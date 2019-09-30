n, m = map(int, input().split())
py = [list(map(int, input().split())) + [0] for _ in range(m)]
py_sorted = sorted(py, key=lambda x: x[1])
d = {}

for pyi in py_sorted:
    if pyi[0] not in d:
        d[pyi[0]] = 1
    else:
        d[pyi[0]] += 1
    pyi[2] = d[pyi[0]]

for pyi in py:
    print(str(pyi[0]).zfill(6) + str(pyi[2]).zfill(6))