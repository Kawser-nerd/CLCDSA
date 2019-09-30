H,W = map(int,input().split())

if H%3==0 or W%3==0:
    print(0) 
else:              
    ans = min(H,W)
    for i in [0,1]:
        for j in [0,1]:
            a = (H//3) + i
            b = (W//2) + j
            tmp = max(a*W,(H-a)*b,(H-a)*(W-b))-min(a*W,(H-a)*b,(H-a)*(W-b))
            ans = min(ans,tmp)
    for i in [0,1]:
        for j in [0,1]:
            a = (W//3) + i
            b = (H//2) + j
            tmp = max(a*H,(W-a)*b,(W-a)*(H-b))-min(a*H,(W-a)*b,(W-a)*(H-b))
            ans = min(ans,tmp)          
    print(ans)