n, m, X, Y = map(int, input().split())
x = list(map(int, input().split()))
y = list(map(int, input().split()))
if X+1 <= Y:
    for Z in range(X+1, Y+1):
        if max(x) < Z and Z <= min(y):
            print('No War')
            exit()
print('War')