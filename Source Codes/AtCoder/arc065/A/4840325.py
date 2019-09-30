S = input()
S = S[::-1]
 
S = S.replace('resare', '')
S = S.replace('esare', '')
S = S.replace('remaerd', '')
S = S.replace('maerd', '')
 
if S:
    print('NO')
else:
    print('YES')