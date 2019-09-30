n=int(input())
p=[]
s=""
def dfs(s,x):
    if x==n:
        return p.append(s)
    else:
        dfs(s+"a",x+1)
        dfs(s+"b",x+1)
        dfs(s+"c",x+1)
dfs("",0)
for y in p:
    print(y)