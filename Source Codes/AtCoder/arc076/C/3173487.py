R, C, N = map(int, input().split())
UP, RIGHT, DOWN, LEFT = [], [], [], []
for i in range(N):
    x1, y1, x2, y2 = map(int, input().split())

    # 2????????
    if 0 < x1 < R and 0 < y1 < C:
        continue
    if 0 < x2 < R and 0 < y2 < C:
        continue

    # 2?????????
    if x1 == 0: UP.append([i, y1])
    elif x1 == R: DOWN.append([i, y1])
    elif y1 == 0: LEFT.append([i, x1])
    elif y1 == C: RIGHT.append([i, x1])

    if x2 == 0: UP.append([i, y2])
    elif x2 == R: DOWN.append([i, y2])
    elif y2 == 0: LEFT.append([i, x2])
    elif y2 == C: RIGHT.append([i, x2])


# ???????????????
UP.sort(key=lambda x: x[1])
RIGHT.sort(key=lambda x: x[1])
DOWN.sort(key=lambda x: x[1], reverse=True)
LEFT.sort(key=lambda x: x[1], reverse=True)

# ?????
Numbers = UP + RIGHT + DOWN + LEFT

# ???????
stack = []
for n, z in Numbers:
    if stack and stack[-1] == n:
        stack.pop()

    else:
        stack.append(n)
print("NO" if stack else "YES")