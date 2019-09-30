s=input()
d=[[0]*(len(s)+1)for i in range(4)]
d[3][-1]+=1
e="ABC"
for i in range(len(s)-1,-1,-1):
    for j in range(3,-1,-1):
        if j==3:
            if s[i]=="?":
                d[3][i]=(d[3][i+1]*3)%(10**9+7)
            else:
                d[3][i]=d[3][i+1]%(10**9+7)
        else:
            if s[i]=="?":
                d[j][i]=(3*d[j][i+1]+d[j+1][i+1])%(10**9+7)
            else:
                d[j][i]=d[j][i+1]
                if e[j]==s[i]:
                    d[j][i]=(d[j][i]+d[j+1][i])%(10**9+7)
print(d[0][0]%(10**9+7))