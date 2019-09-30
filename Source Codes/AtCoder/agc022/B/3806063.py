n = int(input())
if n == 3:
    res = [2, 5, 63]
elif n == 4:
    res = [2, 5, 20, 63]
elif n == 5:
    res = [2, 5, 20, 30, 63]
else:
    res = [i for i in range(1, 30001)
           if i % 6 not in (1, 5)][:n]
    s = sum(res)
    if s % 6 == 2:
        res.pop(res.index(2))
        res.append(30000)
    elif s % 6 == 3:
        res.pop(res.index(3))
        res.append(30000)
    elif s % 6 == 5:
        res.pop(res.index(3))
        res.append(29998)

print(*res)