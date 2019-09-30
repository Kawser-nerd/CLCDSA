def inpl(): return [int(i) for i in input().split()]

R, C, N = inpl()
loopx = {0: [], R: []}
loopy = {0: [], C: []}
for i in range(N):
    x1, y1, x2, y2 = inpl() 
    if (x1 in (0,R) or y1 in (0,C))\
    and (x2 in (0,R) or y2 in (0,C)):
        if x1 in (0,R):
            loopx[x1].append((y1,i))
        elif y1 in (0,C):
            loopy[y1].append((x1,i))
        if x2 in (0,R):
            loopx[x2].append((y2,i))
        elif y2 in (0,C):
            loopy[y2].append((x2,i))
loop = [j for i, j in sorted(loopy[0])] +\
[j for i, j in sorted(loopx[R])] +\
[j for i, j in sorted(loopy[C])][::-1] +\
[j for i, j in sorted(loopx[0])][::-1]
stack = []
for i in loop:
    if not stack:
        stack.append(i)
        continue
    if stack[-1] == i:
        stack.pop()
    else:
        stack.append(i)
if not stack:
    print('YES')
else:
    print('NO')