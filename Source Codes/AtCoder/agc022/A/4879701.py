S = input()
N = len(S)
l = [0 for i in range(26)]
if N < 26:
    for i in range(N):
        l[ord(S[i])-97] += 1
    for i in range(26):
        if l[i] == 0:
            print(S+str(chr(i+97)))
            break
elif S == 'zyxwvutsrqponmlkjihgfedcba':
    print(-1)
else:
    m = 0
    for i in reversed(range(26)):
        if m > ord(S[i])-97:
            id = i
            break
        m = ord(S[i])-97
    for i in range(id,26):
        l[ord(S[i])-97] += 1
    for i in range(len(l)):
        if l[i] == 1 and ord(S[id])-97 < i:
            s = chr(i+97)
            break
    print(S[:id]+str(s))