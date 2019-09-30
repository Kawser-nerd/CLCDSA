N=int(input())
def dfs(i,s):
    if len(s)==N:
        print(s)
        return
    dfs(i+1,str(s)+'a')
    dfs(i+1,str(s)+'b')
    dfs(i+1,str(s)+'c')
    return
dfs(0,'')