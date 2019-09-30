T = int(input())

for num in range(1, T + 1):
    n, l, h = input().split()
    n = int(n)
    l = int(l)
    h = int (h)
    F = list(map(int,input().split()))
    print("Case #", num, ":",sep = '', end = ' ')
    for ans in range(l, h + 1):
        good = True
        for elem in F:
            if elem % ans != 0 and ans % elem != 0:
                good = False
        if good:
            print(ans)
            break
    else:
        print("NO")


