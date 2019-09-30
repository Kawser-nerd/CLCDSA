import sys
H,W,h,w=map(int,input().split())
if H%h==0 and W%w==0:
  print("No")
elif H%h!=0:
  print("Yes")
  p=100000*(h-1)-1
  q=-100000
  L=int(H/h)
  for l in range(L):
    for i in range(W):
      print(p, end = ' ')
    print("")
    for i in range(h-1):
      for i in range(W):
        print(q, end = ' ')
      print("")
  for i in range(W):
    print(p, end = ' ')
  print("")
  for i in range(H-L*h-1):
    for i in range(W):
      print(q, end = ' ')
else:
  print("Yes")
  p=100000*(w-1)-1
  q=-100000
  L=int(W/w)
  s=([p]+[q]*(w-1))*L+[p]+[q]*(W-L*w-1)
  for j in range(H):
    for i in range(W):
      print(s[i], end= " ")
    print("")