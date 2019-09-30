d = {'O':'0','D':'0','I':'1','Z':'2','S':'5','B':'8'}
S = input()
st = ''
for c in S:
    if '0' <= c <= '9':st += c
    else:st += d[c]
print(st)