N=int(input())
a=[int(input()) for x in range(N)]

max=sum(a)
if(max%10!=0):
        ans=max
else:
        ans=10000000
        for i in a:
                if(i%10!=0 and i<ans):
                        ans=i
        ans=max-ans if(ans!=10000000) else 0
print(ans)