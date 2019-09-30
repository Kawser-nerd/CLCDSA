H,W = map(int,input().split())

ans = float("inf")

for w in range(1,W-1) :
    #print("yay")
    s1 = H*w
    
    w2 = (W-w)//2
    s2 = H*w2
    s3 = H*(W-(w+w2))
    calc = max([s1,s2,s3]) - min([s1,s2,s3])
    ans = min(ans,calc)
    #print(s1,s2,s3)
    h2 = H//2
    s2 = h2*(W-w)
    s3 = (H-h2)*(W-w)
    calc = max([s1,s2,s3]) - min([s1,s2,s3])
    ans = min(ans,calc)
    #print(s1,s2,s3)

H,W = W,H    

for w in range(1,W-1) :
    #print("wow")
    s1 = H*w
    
    w2 = (W-w)//2
    s2 = H*w2
    s3 = H*(W-(w+w2))
    calc = max([s1,s2,s3]) - min([s1,s2,s3])
    ans = min(ans,calc)
    #print(s1,s2,s3)
    h2 = H//2
    s2 = h2*(W-w)
    s3 = (H-h2)*(W-w)
    calc = max([s1,s2,s3]) - min([s1,s2,s3])
    ans = min(ans,calc)
    #print(s1,s2,s3)
    
if (H == 2) and (W == 2) :
    ans = 1

print(ans)