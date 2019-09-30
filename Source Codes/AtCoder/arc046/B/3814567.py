n=int(input())
a,b=map(int,input().split())
print(["Aoki","Takahashi"][(a==b and n%(a+1)!=0) or a>b or n<=a])