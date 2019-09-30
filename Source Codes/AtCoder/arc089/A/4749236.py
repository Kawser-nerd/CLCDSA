n=int(input())
x=[[0,0,0]]+[list(map(int,input().split()))for i in range(n)]
y=[]
for i in range(n):
    s,t,r=x[i+1]
    q,p,w=x[i]
    temp=s-q
    abso=abs(t-p)+abs(r-w)
    if temp<abso or (temp%2!=abso%2):
        print("No")
        exit()
print("Yes")