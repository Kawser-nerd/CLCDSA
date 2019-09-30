a,b=map(int,input().split())
k=int(input())
if b>=k:
    print(a+k)
else:
    print(a-(k-b)+b)