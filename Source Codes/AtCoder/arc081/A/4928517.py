from collections import Counter
N = int(input())
A = list(map(int,input().split()))
c = Counter(A)
op = []
for a, cnt in c.items():
    for _ in range(cnt // 2):
        op.append(a)
op.sort(reverse=True)
if len(op) < 2:
    print(0)
else:
    print(op[0]*op[1])