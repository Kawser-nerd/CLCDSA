H,W = map(int,input().split())
ans = float('inf')
for h in range(1,H):
  if (H-h)%2 == 0:
    k = max(h*W,(H-h)*W//2)-min(h*W,(H-h)*W//2)
    if ans > k:
      ans = k
  else:
    k = max(h*W,((H-h)//2)*W,((H-h)-(H-h)//2)*W)-min(h*W,((H-h)//2)*W,((H-h)-(H-h)//2)*W)
    if ans > k:
      ans = k
for w in range(1,W):
  if (W-w)%2 == 0:
    k = max(w*H,(W-w)*H//2)-min(w*H,(W-w)*H//2)
    if ans > k:
      ans = k
  else:
    k = max(w*H,((W-w)//2)*H,((W-w)-(W-w)//2)*H)-min(w*H,((W-w)//2)*H,((W-w)-(W-w)//2)*H)
    if ans > k:
      ans = k
for w in range(1,W):
  if H%2 == 0:
    l = max(w*H,(W-w)*H//2)-min(w*H,(W-w)*H//2)
    if ans > l:
      ans = l
  else:
    l = max(w*H,(W-w)*(H//2),(W-w)*(H-H//2))-min(w*H,(W-w)*(H//2),(W-w)*(H-H//2))
    if ans > l:
      ans = l
for h in range(1,H):
  if W%2 == 0:
    l = max(h*W,(H-h)*W//2)-min(h*W,(H-h)*W//2)
    if ans > l:
      ans = l
  else:
    l = max(h*W,(H-h)*(W//2),(H-h)*(W-W//2))-min(h*W,(H-h)*(W-W//2),(H-h)*(W//2))
    if ans > l:
      ans = l
print(ans)