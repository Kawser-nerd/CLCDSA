n,d,k=map(int,input().split())
s=[list(map(int,input().split()))for i in range(d)]
for j in range(k):
    p,t=map(int,input().split())
    for i in range(d):
        if s[i][0]<=p<=s[i][1]:
            if s[i][0]<=t<=s[i][1]:
                break
            elif t<=s[i][0]:
                p=s[i][0]
            else:
                p=s[i][1]
    print(i+1)