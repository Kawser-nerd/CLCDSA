def main():
    N,x = map(int,input().split())
    num = x
    a_s = list(map(int,input().split()))
    a_s.sort()
    cnt = 0
    for i,a in enumerate(a_s):
        if num >= a:
            num -= a
            cnt += 1

    if cnt == N and num > 0:
        cnt -= 1
    print(cnt)
if __name__ == '__main__':
    main()