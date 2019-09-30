s=list(input().split())
t={"Left":"<","Right":">","AtCoder":"A"}
ans=[]
for x in s:
  ans.append(t[x])
print(" ".join(ans))