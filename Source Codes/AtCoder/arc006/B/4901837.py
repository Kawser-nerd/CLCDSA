N, L = map(int, input().split())
A = [list(input()) for i in range(L)]
B = list(input())
ans = B.index('o')
for a in A[::-1]:
    if ans != 0 and a[ans-1] == '-':
        ans -= 2
    elif ans != (N - 1) * 2 and a[ans+1] == '-':
        ans += 2
print(ans // 2 + 1)