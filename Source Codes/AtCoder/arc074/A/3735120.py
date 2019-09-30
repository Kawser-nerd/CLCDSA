from math import ceil
H,W=map(int,input().split())
ans=float("inf")
for h in range(1,H):
  m=min(h*W,(H-h)*(W//2),(H-h)*ceil(W/2))
  M=max(h*W,(H-h)*(W//2),(H-h)*ceil(W/2))
  ans=min(ans,M-m)
  m=min(h*W,((H-h)//2)*(W),ceil((H-h)/2)*(W))
  M=max(h*W,((H-h)//2)*(W),ceil((H-h)/2)*(W))
  ans=min(ans,M-m)
for w in range(1,W):
  m=min(w*H,(W-w)*(H//2),(W-w)*ceil(H/2))
  M=max(w*H,(W-w)*(H//2),(W-w)*ceil(H/2))
  ans=min(ans,M-m)
  m=min(w*H,((W-w)//2)*H,ceil((W-w)/2)*H)
  M=max(w*H,((W-w)//2)*H,ceil((W-w)/2)*H)
  ans=min(ans,M-m)
print(ans)