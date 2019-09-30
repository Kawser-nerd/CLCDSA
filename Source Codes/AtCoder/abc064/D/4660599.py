N=int(input())
S=input()
res=S
while '()' in res:
    res=res.replace('()','')
ans='('*res.count(')')+S+')'*res.count('(')
print(ans)