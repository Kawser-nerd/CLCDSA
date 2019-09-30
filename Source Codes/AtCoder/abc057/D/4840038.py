def fuct(n:int)->int:
    if n<=1:
        return 1
    else:
        return n * fuct(n-1)

def main():
    n,a,b = map(int, input().split())
    v = list(map(int, input().split()))
    v = sorted(v, reverse=True)
    print(sum(v[:a])/a)
    res = 0

    if v[0]==v[a-1]:
        vn = v.count(v[0])
        for r in range(a,b+1):
            res += fuct(vn)//(fuct(vn-r) * fuct(r))
    else:
        vn = v.count(v[a-1])
        r = v[:a].count(v[a-1])
        res += fuct(vn)//(fuct(vn-r) * fuct(r))

    print(res)

if __name__ == '__main__':
    main()