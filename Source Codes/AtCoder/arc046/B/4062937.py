n = int(input())
a,b = map(int,input().split())
if a > b:
    print("Takahashi")
elif a == b:
    if n%(a+1)==0:
        print("Aoki")
    else:
        print("Takahashi")
elif a < b:
    if n <= a:
        print("Takahashi")
    else:
        print("Aoki")