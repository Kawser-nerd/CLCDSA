s = int(input())
a = [s]

i = 0
flag = 0
while(True):
    if a[i] % 2 == 0:
        new_a = int(a[i] / 2)
    else:
        new_a = int(3 * a[i] + 1)
    i += 1
    for ai in a:
        if new_a == ai:
            flag = 1
            break
    if flag == 1:
        break
    else:
        a.append(new_a)

print(i + 1)