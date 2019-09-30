I, O, T, J, L, S, Z = map(int, input().split())
res = O
res += sum(map(lambda x: x//2*2, [I, J, L]))
res += 3*min(map(lambda x: x%2, [I, J, L]))

res2 = O
if I and J and L:
    res2 += 3
    I, J, L = map(lambda x: x-1, [I, J, L])

res2 += sum(map(lambda x: x//2*2, [I, J, L]))
print(max(res, res2))