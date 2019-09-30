import sys
input = sys.stdin.readline
s, t, q = list(input()), list(input()), int(input())
ssum, tsum = [0], [0]
for i in range(len(s)):
    if s[i]=="A": ssum.append(ssum[-1]+1)
    else: ssum.append(ssum[-1]+2)
for i in range(len(t)):
    if t[i]=="A": tsum.append(tsum[-1]+1)
    else: tsum.append(tsum[-1]+2)
for i in range(q):
    a,b,c,d = map(int,input().split())
    sa = (ssum[b]-ssum[a-1])-(tsum[d]-tsum[c-1])
    if abs(sa)%3==0:print("YES")
    else: print("NO")