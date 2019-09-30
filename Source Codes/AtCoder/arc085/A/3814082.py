N, M = map(int, input().split(' '))

once = 100 * (N-M) + 1900 * M
P = 2 ** M
ans = once * P
print(ans)