n = int(input())
s = list(map(int,input().split()))
p = [0 for i in range(10**5+1)]
l,r,m = 0,0,0
while r<n:
    if p[s[r]]==0:
        p[s[r]]+=1
        r+=1
    else:
        p[s[l]]-=1
        l+=1
    m = max(m,r-l)
print(m)