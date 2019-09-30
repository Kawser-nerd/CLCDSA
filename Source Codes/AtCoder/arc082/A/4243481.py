s=[0]*(10**5+2)
n=int(input())
a=list(map(int,input().split()))
for i in a:
    s[i-1]+=1
    s[i]+=1
    s[i+1]+=1
print(max(s))