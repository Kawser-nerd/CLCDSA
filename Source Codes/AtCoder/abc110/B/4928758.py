n, m, x, y = list(map(int, input().split()))
x_li = list(map(int, input().split()))
y_li = list(map(int, input().split()))
ans_f = 0
for z in range(x + 1, y + 1):
    x_not_f = 0
    y_not_f = 0
    for i in x_li:
        if z <= i:
            x_not_f = 1
    for i in y_li:
        if z > i:
            y_not_f = 1
    if x_not_f == 0 and y_not_f == 0:
        ans_f = 1
        break

if ans_f == 1:
    print("No War")
else:
    print("War")