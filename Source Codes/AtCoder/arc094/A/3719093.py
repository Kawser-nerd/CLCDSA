def main():
    num = [int(i) for i in input().split()]
    num.sort()
    ans = 0
    ans += (num[2]-num[1])
    ans+=(num[1]-num[0])//2
    if (num[1]-num[0])%2==1:
        ans+=2
    print(ans)


if __name__ == '__main__':
    main()