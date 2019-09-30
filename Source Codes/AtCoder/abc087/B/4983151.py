a,b,c,x = map(int, [input() for i in range(4)])

y = 0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if x == 500*i + 100*j + 50*k :
                y += 1
                # if ( x < 500*i + 100*b + 50*c ):
                #    break

print(y)