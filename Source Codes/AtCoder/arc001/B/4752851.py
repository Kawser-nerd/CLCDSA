A, B = map(int,input().split())
offset = 100
table = [40 for _ in range(300)]
table[A+offset] = 0
while True:
    l = []
    for i in range(len(table)):
        if table[i] != 40:
            l.append(i)
    for i in l:
        for x in [1,5,10]:
            if table[B+offset] != 40:
                print(table[B+offset])
                quit()
            table[i+x] = min(table[i+x],table[i] + 1)
            table[i-x] = min(table[i-x],table[i] + 1)