N = int(input())
m = [input() for _ in range(N)]
#print(m)
b = 0
cont = False
for j in range(9):
    for i in range(N):
        f = m[i][j]
        if f != 'o':
            if cont == True:
                cont = False
            if f == 'x':
                b += 1
        else:
            if not cont:
                b += 1
                cont = True
    else:
        cont = False
print(b)