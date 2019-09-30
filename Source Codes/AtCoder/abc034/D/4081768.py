N,K=map(int,input().split())
WP=[list(map(int,input().split())) for i in range(N)]

MIN=0
MAX=100

while MAX-MIN>10**(-8):
    x=(MAX+MIN)/2
    
    NEEDLIST=[WP[i][0]*x-WP[i][0]*WP[i][1] for i in range(N)]
    NEEDLIST.sort()

    if sum(NEEDLIST[:K])>=0:
        MAX=x
    else:
        MIN=x

print((MAX+MIN)/2)