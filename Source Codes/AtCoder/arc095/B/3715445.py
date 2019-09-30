def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    ma = max(a)
    diff = 100000000000000
    ans = 0
    for aa in a:
        t = abs(ma//2-aa)
        if ma != aa and diff > t:
            diff = t
            ans = aa
    print(ma,ans)

if __name__ == '__main__':
    main()