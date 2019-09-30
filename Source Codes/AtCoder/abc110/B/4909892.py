N, M, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
x.sort()
y.sort()
z = []

if X < Y:
    for i in range(X+1, Y+1):
        z.append(i)
    for Z in z:
        if x[N-1] < Z <= y[0]:
            print('No War')
            exit()
    print('War')
else:
    print('War')