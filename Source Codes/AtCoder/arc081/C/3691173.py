from collections import deque
from sys import exit

As = input()

As = [ord(A) - ord('a') for A in As]
lenA = len(As)
posChars = [lenA] * 26
posNexts = [[] for _ in range(lenA + 1)]
for i in reversed(range(lenA)):
    posNexts[i + 1] = posChars.copy()
    posChars[As[i]] = i
posNexts[0] = posChars.copy()

prevs = [None] * lenA
Q = deque()
Q.append((0, -1))
while Q:
    lenAns, pos = Q.popleft()
    for ch in range(26):
        posNext = posNexts[pos + 1][ch]
        if posNext == lenA:
            ans = [chr(ord('a') + ch)]
            while pos != -1:
                ans.append(chr(ord('a') + As[pos]))
                pos = prevs[pos]
            print(''.join(reversed(ans)))
            exit()
        if prevs[posNext] is None:
            prevs[posNext] = pos
            Q.append((lenAns + 1, posNext))