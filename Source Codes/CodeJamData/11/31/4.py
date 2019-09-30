N = int(input())

for num in range(1, N + 1):
    r, c = input().split()
    r = int(r)
    c = int(c)
    M = [0] * r
    for i in range(r):
        M[i] = list(input())
    ans = True
    for i in range(r - 1):
        for j in range(c - 1):
            if M[i][j] == '#':
                if M[i+1][j] == '#' and M[i][j+1] == '#' and M[i+1][j+1] == '#':
                    M[i][j] = '/'
                    M[i][j+1] = '\\'
                    M[i+1][j] = '\\'
                    M[i+1][j+1] = '/'
                else:
                    ans = False
        if  '#' in M[i]:
            ans = False
    if '#' in M[-1]:
        ans = False
    print("Case #", num, ":",sep = '')
    if ans:
        for i in range(r):
            print(''.join(M[i]))
    else:
        print("Impossible")


