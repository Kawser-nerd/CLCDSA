def main():
    n, m, d = map(int, input().split())
    a = [int(s) - 1 for s in input().split()]
    t = [i for i in range(n)]

    for i in reversed(a):
        t[i], t[i + 1] = t[i + 1], t[i]
    
    p = [i for i in range(n)]

    while d:
        if d & 0x01 == 1:
            p = [t[p[i]] for i in range(n)]
        t = [t[t[i]] for i in range(n)]
        d >>= 1
    
    for i in p:
        print(i + 1)

main()