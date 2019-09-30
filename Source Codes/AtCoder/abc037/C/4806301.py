from itertools import accumulate as ac

N, K = map(int, input().split())
lst_a = list(map(int, input().split()))
ans = 0


lst_S = list(ac(lst_a))
for i in range(N-K+1):
    if i == 0:
        ans += (lst_S[i+K-1] - 0)
    else:
        ans += (lst_S[i+K-1] - lst_S[i-1])
print(ans)