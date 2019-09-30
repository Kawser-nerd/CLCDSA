N, L = map(int, input().split())

make = lambda:[None, None, 0]
root = make()
def construct(s):
    n = root
    for i in s:
        if n[i] is None:
            n[i] = n = make()
        else:
            n = n[i]
    n[2] = 1

for i in range(N):
    s = map(int, input())
    construct(s)

caps = {}
st = [(root, 0, 0)]
while st:
    n, i, l = st.pop()
    if i:
        if n[1] is None:
            caps[L - l] = caps.get(L - l, 0) + 1
        else:
            if not n[1][2]:
                st.append((n[1], 0, l+1))
    else:
        st.append((n, 1, l))
        if n[0] is None:
            caps[L - l] = caps.get(L - l, 0) + 1
        else:
            if not n[0][2]:
                st.append((n[0], 0, l+1))
ans = 0
for v in caps:
    k = caps[v]
    if k % 2 == 0:
        continue
    v -= 1
    r = 1
    while v % 4 == 3:
        v //= 4
        r *= 4
    if v % 4 == 1:
        ans ^= r * 2
    else:
        ans ^= r
print('Alice' if ans else 'Bob')