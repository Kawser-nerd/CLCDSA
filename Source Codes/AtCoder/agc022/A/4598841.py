s=input()
last='zyxwvutsrqponmlkjihgfedcba'
if s==last:print(-1);exit()
d={c for c in s}
lest={c for c in last}-d
if len(lest)>0:print(s+sorted(lest)[0]);exit()
m=[s[-1]]
for i in range(25)[::-1]:
  for n in sorted(m):
    if s[i]<n:print(s[:i]+n);exit()
  m+=[s[i]]