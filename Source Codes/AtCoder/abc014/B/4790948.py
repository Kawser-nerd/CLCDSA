n, x = map(int, input().split())
a = list(map(int, input().split()))
x = list(format(x, 'b'))
while len(x) < n:
    x.insert(0, '0')
x.reverse()
print(sum([a[i] for i, s in enumerate(x) if s == '1']))