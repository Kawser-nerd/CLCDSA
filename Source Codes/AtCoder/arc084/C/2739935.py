K, N = map(int, input().split())

if K % 2 == 0:
    ans = [K//2] + [K] * (N-1)
else:
    ans = [(K+1)//2] * N
    for i in range(N//2):
        if ans[-1] == 1:
            ans.pop()
        else:
            ans[-1] -= 1
            ans += [K] * (N - len(ans))

print(' '.join(map(str, ans)))