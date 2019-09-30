def main():
    K,N = map(int,input().split())

    if K % 2 == 0:
        ans = [K//2]
        for i in range(N-1):
            ans.append(K)
    else:
        back = N // 2
        mid = K // 2 + 1
        ans = [mid for i in range(N)]
        for i in range(back):
            if ans[-1] == 1:
                ans.pop()
            else:
                ans[-1] -= 1
                while len(ans) < N:
                    ans.append(K)
    print(' '.join(map(str, ans)))

if __name__ == '__main__':
    main()