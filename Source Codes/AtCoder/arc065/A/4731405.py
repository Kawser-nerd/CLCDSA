l = ['maerd', 'remaerd', 'esare', 'resare']
flag = False
S = input()
S = ''.join(list(reversed(S)))
j = 0
for i in range(len(S)+1):
    if S[j:i] in l:
        j=i
        flag = True
    else:
        flag = False
print("YES" if flag else "NO")