s = input()

if len(s) != 26:
    se = set([])
    for w in s:
        se.add(w)

    for i in range(26):
        w = chr(ord('a')+i)
        if w not in se:
            print(s + w)
            exit()

if s == "zyxwvutsrqponmlkjihgfedcba":
    print(-1)
    exit()

se = set([])
for i in reversed(range(26)):
    se.add(s[i])
    for j in range(ord(s[i])-ord('a')+1, 26):
        if chr(ord('a')+j) in se:
            print(s[:i]+chr(ord('a')+j))
            exit()