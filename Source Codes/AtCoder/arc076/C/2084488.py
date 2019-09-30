R, C, N = map(int, input().split())
def calc(x, y):
    if x == 0 or y == C:
        return x + y
    return 2*R + 2*C - x - y
A = {}
for i in range(N):
    x1, y1, x2, y2 = map(int, input().split())
    if not ((x1 in [0, R] or y1 in [0, C]) and (x2 in [0, R] or y2 in [0, C])):
        continue
    A[calc(x1, y1)] = i
    A[calc(x2, y2)] = i

st = []
for i, a in sorted(A.items()):
    if st and st[-1] == a:
        st.pop()
    elif a is not None:
        st.append(a)
print('YES' if not st else 'NO')