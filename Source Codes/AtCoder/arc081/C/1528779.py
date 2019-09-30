from collections import deque
alpha = "abcdefghijklmnopqrstuvwxyz"
A = input()
n = len(A)
B = ord('a')

links = [None]*(n+3)

link = [n]*26
for i in range(n-1, -1, -1):
    links[i] = link[:]
    link[ord(A[i]) - B] = i
links[-1] = link

deq = deque()
deq.append(-1)
prev = {-1: (None, 0)}
while deq:
    v = deq.popleft()
    if v == n:
        break
    link = links[v]
    for c in range(26):
        if link[c] in prev:
            continue
        prev[link[c]] = (v, c)
        deq.append(link[c])
v = n
ans = []
while v is not None:
    v, c = prev[v]
    ans.append(chr(c+B))
ans.reverse()
print("".join(ans[1:]))