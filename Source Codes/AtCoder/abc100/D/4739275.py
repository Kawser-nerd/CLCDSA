n, m = map(int, input().split())
xyz = [ [int(x) for x in input().split()] for _ in range(n) ]

ans = 0

for bit in range(2**3):
    s = []
    is_plus = [1, 1, 1]
    for i in range(3):
        if bit>>i & 1:
            is_plus[i] = -1

    for (x, y, z) in xyz:
        s += [ x * is_plus[0] + y * is_plus[1] + z * is_plus[2] ]

    s.sort(reverse=True)
    ans = max(ans, sum(s[:m]))

print(ans)