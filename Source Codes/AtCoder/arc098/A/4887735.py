from sys import stdin
n = int(stdin.readline().rstrip())
s = list(stdin.readline().rstrip())
wl = [0]
el = [0]
ans=[]
for i in range(n):
    wl.append(wl[i]+1 if s[i] == 'W' else wl[i])
for i in range(n):
    el.append(el[i]+1 if s[i] == 'E' else el[i])
for i in range(n+1):
    ans.append(wl[i]+el[-1]-el[i])
print(min(ans))