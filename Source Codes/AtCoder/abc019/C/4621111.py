N=int(input())
ans=set()
for a in map(int,input().split()):
    while True:
        if a%2==1:
            ans|={a,}
            break
        else:a//=2
print(len(ans))