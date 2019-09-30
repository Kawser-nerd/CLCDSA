H,W=map(int,input().split())
if (H*W)%3==0:
    print(0)
else:
    s=10**10
    t=10**10
    for i in range(H):
        x=max(abs(W*i-(H-i)*(W//2)),abs(W*i-(H-i)*(W//2+W%2)),(H-i)*(W%2))
        y=max(abs(W*i-W*((H-i)//2)),abs(W*i-W*((H-i)//2+(H-i)%2)),W*((H-i)%2))
        b=min(x,y)
        if b<=s:
            s=b
        else:
            break
    for j in range(W):
        v=max(abs(H*j-(W-j)*(H//2)),abs(H*j-(W-j)*(H//2+H%2)),(W-j)*(H%2))
        w=max(abs(H*j-H*((W-j)//2)),abs(H*j-H*((W-j)//2+(W-j)%2)),H*((W-j)%2))
        c=min(v,w)
        if c<=t:
            t=c
        else:
            break
    
    print(min(s,t))