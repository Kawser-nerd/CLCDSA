N = int(input())
d = [int(input()) for _ in range(N)]

ans = '{}\n{}'.format(
    str(sum(d)),
    str(max(2 * max(d) - sum(d), 0))
)
print(ans)