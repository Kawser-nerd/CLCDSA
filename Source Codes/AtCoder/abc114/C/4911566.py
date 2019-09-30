N=int(input())

def dfs(s):
    if len(s)==len(str(N)):
        return 0
    ans=0
    for c in "357":
        if int(s+c)<=N and all(a in s+c for a in "357"):
            ans+=1
        ans+=dfs(s+c)
    return ans
print(dfs(''))