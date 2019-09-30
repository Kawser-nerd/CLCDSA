n=int(input())
a,b=map(int,input().split())
if a>b:
    print("Takahashi")
elif a==b:
    if n%(a+1)!=0:
        print("Takahashi")
    else:
        print("Aoki")
else:
    if a>=n:
        print("Takahashi")
    else:
        print("Aoki")