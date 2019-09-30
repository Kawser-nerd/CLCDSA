S = input()
S = S[::-1]
snipetts = [s[::-1] for s in ['dream', 'dreamer', 'erase', 'eraser']]

found = True
index = 0
while found:
    found = False
    for s in snipetts:
        if S[index:index+len(s)] == s:
            index += len(s)
            found = True
            break

if index == len(S):
    print('YES')
else:
    print('NO')