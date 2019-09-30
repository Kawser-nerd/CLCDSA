R,C,N = map(int,input().split())

def outer_pos(x,y):
    if (0 < x < R) and (0 < y < C): return -1
    if y == 0: return x
    if x == R: return R + y
    if y == C: return R + C + (R-x)
    return R + C + R + (C-y)

outer = []
for i in range(N):
    x1,y1,x2,y2 = map(int,input().split())
    p1 = outer_pos(x1,y1)
    p2 = outer_pos(x2,y2)
    if p1 < 0 or p2 < 0: continue
    outer.append((p1,i))
    outer.append((p2,i))
outer.sort()

stack = []
for p,i in outer:
    if len(stack) == 0 or stack[-1] != i:
        stack.append(i)
    else:
        stack.pop()
print('NO' if stack else 'YES')