K=int(input())
Q=K//50
R=K%50
ans=[49+Q]*50
for i in range(50):
    if i<50-R:
        ans[i]-=R
    else:
        ans[i]+=50-R+1
print(50)
print(' '.join(map(str,ans)))