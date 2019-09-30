def main():
    n = int(input())
    x = [int(i) for i in input().split()]
    newx = sorted(x)
    ans = dict()
    for i,xx in enumerate(newx):
        if i+1 <= n//2:
            ans[xx] = newx[n//2]
        else:
            ans[xx] = newx[n//2-1]
    for xx in x:
        print(ans[xx])

if __name__ == '__main__':
    main()