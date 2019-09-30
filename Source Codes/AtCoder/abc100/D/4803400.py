import sys

def change(p1,p2,p3):
    b=[[val[i][0]*p1,val[i][1]*p2,val[i][2]*p3] for i in range(N)]
    c=[sum(b[i]) for i in range(N)]
    c.sort(reverse=True)
    return max(abs(sum(c[:M])),abs(sum(c[-M:])))


N,M=map(int,input().split())
val=[list(map(int,input().split())) for i in range(N)]
if M==0:
    print(0)
    sys.exit()


ans=max(change(1,1,1),change(1,1,-1),change(1,-1,1),change(1,-1,-1))
print(ans)