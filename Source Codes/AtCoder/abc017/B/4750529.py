X = input()
p = len(X) - 1
while p >= 0:
    if X[p] == 'o' or X[p] == 'k' or X[p] == 'u':
        p -= 1
    elif X[p] == 'h':
        if p - 1 >= 0 and X[p - 1] == 'c':
            p -= 2
        else:
            print('NO')
            exit(0)
    else:
        print('NO')
        exit(0)
print('YES')