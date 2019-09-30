d = {'Left':'<', 'Right':'>', 'AtCoder':'A'}
s = list(input().split())
l = [d[c] for c in s]
print(*l)