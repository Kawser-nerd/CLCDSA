n = int(input())
magic_up = []
magic_down = []
for i in range(n):
    a, b = map(int, input().split())
    if a < b:
        magic_down.append((a, b))
    else:
        magic_up.append((b, a))
magic_down.sort()
magic_up.sort()
tmp = 0
max_tmp = 0
for a, b in magic_down:
    tmp += a
    max_tmp = max(max_tmp, tmp)
    tmp -= b
for b, a in magic_up[::-1]:
    tmp += a
    max_tmp = max(max_tmp, tmp)
    tmp -= b
print(max_tmp)