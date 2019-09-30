sa=input()
sb=input()
sc=input()
from collections import deque
a = deque(sa)
b = deque(sb)
c = deque(sc)

x = a.popleft()
while True:
    if x == 'a':
        if not a:
            print('A')
            break
        x = a.popleft()
    elif x == 'b':
        if not b:
            print('B')
            break
        x = b.popleft()
    elif x == 'c':
        if not c:
            print('C')
            break
        x = c.popleft()