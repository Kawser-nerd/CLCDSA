n = int(input())
s=[]
for i in range(n):
    s.append(list(input()))
ns=[]
for k in range(n):
    for j in reversed(range(0,n)):
        ns.append(s[j][k])

for m in range(n):
    print(''.join(ns[n*m:n*(m+1)]))