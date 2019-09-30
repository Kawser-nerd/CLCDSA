import sys

sys.stdin.readline()
lst = list(map(int, sys.stdin.readline().split()))
N = len(lst)

max_val, max_t = lst[0], 0
min_val, min_t = lst[0], 0

for t in range(1, len(lst)):
    if max_val < lst[t]:
        max_val = lst[t]
        max_t = t
    if min_val > lst[t]:
        min_val = lst[t]
        min_t = t

if max_val >= -min_val:
    print(2 * N - 2)
    for i in range(len(lst)):
        if i == max_t:
            continue
        print(max_t + 1, i + 1)
    for i in range(1, len(lst)):
        print(i, i + 1)
else:
    print(2 * N - 2)
    for i in range(len(lst)):
        if i == min_t:
            continue
        print(min_t + 1, i + 1)
    for i in range(len(lst), 1, -1):
        print(i, i - 1)