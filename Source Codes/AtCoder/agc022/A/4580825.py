S = input()
if len(S) < 26:
    for i in range(26):
        c = chr(ord('a')+i)
        if c not in S:
            print(S + c)
            exit()
if S == 'zyxwvutsrqponmlkjihgfedcba':
    print(-1)
    exit()

cs = set()
for i in range(25):
    t,tt = S[-i-1],S[-i-2]
    cs.add(t)
    if tt < t:
        last = 'z'
        for c in cs:
            if c < tt: continue
            last = min(last, c)
        print(S[:-i-2] + last)
        exit()