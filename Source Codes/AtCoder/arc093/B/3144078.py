A,B =list(map(int, input().split()))

print(100,100)

x1 = ''.join(['.']*100)
y1 = ''.join(['#']*100)

for i in range(25):
    x = ['.'] * 100
    for j in range(50):
        if B>1:
            x[2*j] = '#'
            B -= 1
    print(''.join(x))
    print(x1)

for i in range(25):
    print(y1)
    y = ['#'] * 100
    for j in range(50):
        if A>1:
            y[2*j] = '.'
            A -= 1
    print(''.join(y))