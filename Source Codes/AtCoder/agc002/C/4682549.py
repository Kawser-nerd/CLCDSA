N, L = map(int, input().split())
a = list(map(int, input().split()))

I = [i + 1 for i in range(N - 1) if a[i] + a[i + 1] >= L]
ans = (
    'Possible\n{}'.format(
        '\n'.join(
            map(
                str,
                list(range(1, I[0])) + list(range(N - 1, I[0], -1)) + [I[0]]
            )
        )
    ) if I else
    'Impossible'
)

print(ans)