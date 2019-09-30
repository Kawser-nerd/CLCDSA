H, W = map(int, input().split())

box = []
for i in range(H):
    a = [j for j in input()]
    if all(j == '.' for j in a):
        pass
    else:
        box.append(a)

idx = []
for i in range(len(box[0])):
    ct = 0
    for j in box:
        if j[i] == '.':
            ct += 1
    if ct == len(box):
        idx.append(i)

for i in box:
    for j in range(len(i)):
        if j < len(i)-1:
            if j in idx:
                pass
            else:
                print(i[j], end='')
        else:
            if j in idx:
                print()
            else:
                print(i[j])