from collections import deque

x = input()
q = deque(x[0])

for i in range(1, len(x)):
    if q:
        p = q.pop()
        if p == 'S' and x[i] == 'T':
            pass
        else:
            q.append(p)
            q.append(x[i])
    else:
        q.append(x[i])
print(len(q))