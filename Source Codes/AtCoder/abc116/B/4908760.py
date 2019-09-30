s=int(input())

a = [s]
i = 1
while True:
    i += 1
    if a[-1] % 2 == 0:
        a.append(a[-1] / 2)
    else:
        a.append(a[-1] * 3 + 1)

    a_unique = list(set(a))
    if len(a) != len(a_unique):
        break


print(i)