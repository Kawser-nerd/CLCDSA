N, M = map(int, input().split())

py = []
for i in range(M):
    py.append(list(map(int, input().split())))
    py[i].append(i)

py.sort(key=lambda x: (x[0], x[1]))

number = []
for i in range(M):
    if i == 0:
        ct = 1
        number.append((str(py[i][0]).zfill(6) + str(ct).zfill(6), py[i][2]))
    else:
        if py[i-1][0] == py[i][0]:
            ct += 1
            number.append((str(py[i][0]).zfill(6) + str(ct).zfill(6), py[i][2]))
        else:
            ct = 1
            number.append((str(py[i][0]).zfill(6) + str(ct).zfill(6), py[i][2]))

number.sort(key=lambda x: x[1])

for i in number:
    print(i[0])