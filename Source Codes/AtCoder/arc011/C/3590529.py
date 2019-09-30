import sys
from collections import deque

first, last = input().split()
N = int(input())
word_set = {l.rstrip() for l in sys.stdin} | {first, last}
alphabets = [chr(i) for i in range(97, 123)]

dq = deque([(first, [])])
popleft, append = dq.popleft, dq.append
used = {first}
add_used = used.add

while dq:
    word, path = popleft()
    path = path + [word]
    if word == last:
        if len(path) == 1:
            path += path
        print(len(path)-2)
        print(*path, sep="\n")
        exit()
    s = word_set & {word[:i]+c+word[i+1:] for i in range(len(word)) for c in alphabets} - used

    for w in s:
        add_used(w)
        append((w, path))
else:
    print(-1)