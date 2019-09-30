s = int(input())
a = [s]
i = 0
while True:
    if a[i] % 2 == 0:
        a.append(a[i] / 2)
    else:
        a.append(3 * a[i] + 1)
    i += 1
    if a[i] in a[:i]:
        print(int(i+1))
        exit()