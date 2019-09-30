H, W = map(int, input().split())
data= [str(input()) for i in range(H)]

new_data = []
row = [0] * W
for d in data:
    if d.count('.') == W:
        continue
    new_data.append(d)
    for i in range(W):
        if d[i] == '.':
            row[i] += 1

num = len(new_data)

for d in new_data:
    for i in range(W):
        if row[i] != num:
            print(d[i], end='')
    print()