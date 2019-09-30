N = int(input())

le = len(str(N))
al = ['3','5','7']
al2 = []
for i in range(le-1):
    al1 = []
    for n in al:
        a = int(str(n)+'3')
        b = int(str(n)+'5')
        c = int(str(n)+'7')
        al1.append(a)
        al1.append(b)
        al1.append(c)
        al2.append(a)
        al2.append(b)
        al2.append(c)
    al = al1

cnt = 0
for n in al2:
    if n <= N:
        if all(str(n).count(c) > 0 for c in '753'):
            cnt += 1

print(cnt)