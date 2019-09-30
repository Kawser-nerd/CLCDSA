N, P = map(int, input().split())
lst_A = list(map(int, input().split()))
lst_odd_even = [x%2 for x in lst_A]

if 1 in lst_odd_even:
    ans = 2 ** (N-1)
else:
    if P == 0:
        ans = 2 ** N
    else:
        ans = 0

print(ans)