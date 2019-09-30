h, k = map(int, input().split())
mat = [input() for _ in range(h)]
for _  in range(2):
    poplist = []
    for i, row in enumerate(mat):
        for x in row:
            if x == '#':
                break
        else:
            poplist.append(i)
    poplist.reverse()
    for i in poplist:
        mat.pop(i)
    poplist = []
    mat = [x for x in zip(*mat)]
for row in mat:
    print(''.join(row))