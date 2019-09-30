a,b,c=map(int,input().split())
if a==b==c:
    print(-int(not a%2))
else:
    cnt=0
    while not (a%2 or b%2 or c%2):
        cnt+=1
        a,b,c=(b+c)//2,(c+a)//2,(a+b)//2
    print(cnt)