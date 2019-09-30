from itertools import accumulate as ac


N, K = map(int, input().split())
lst_a = list(map(int, input().split()))
lst_imosu = [0] * (N + 1)

for l in range(N-K+1):
    r = l + K
    lst_imosu[l] += 1
    lst_imosu[r] -= 1
lst_ac = list(ac(lst_imosu))[0:N]


ans = 0
for a, i_ac in zip(lst_a, lst_ac):
    ans += a*i_ac
print(ans)