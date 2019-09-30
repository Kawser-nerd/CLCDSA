# https://qiita.com/drken/items/56a6b68edef8fc605821#%E5%95%8F%E9%A1%8C-1-aoj-0516---%E6%9C%80%E5%A4%A7%E3%81%AE%E5%92%8C-joi-2006-%E6%9C%AC%E9%81%B8-a

INPUT_MAX = 101010

is_prime = [1] * INPUT_MAX  # True or False
is_prime[0] = 0
is_prime[1] = 0

# ???????????
for i in range(2, INPUT_MAX):
    if not is_prime[i]:
        continue
    for k in range(i * 2, INPUT_MAX, i):
        is_prime[k] = 0

# 2017-like ?????
a = [0] * INPUT_MAX
for i in range(INPUT_MAX):
    if i % 2 == 0:
        continue
    if (i + 1) % 2 != 0: continue
    if is_prime[i] and is_prime[int((i + 1) / 2)]:
        a[i] = 1

# ???
s = [0] * (INPUT_MAX + 1)
for i in range(INPUT_MAX):
    s[i + 1] = s[i] + a[i]

Q = int(input())
for q in range(Q):
    l, r = map(int, input().split())
    r += 1
    print(s[r] - s[l])