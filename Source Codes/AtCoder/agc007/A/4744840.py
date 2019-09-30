h,w=map(int,input().split());c=0
for i in range(h):
  a=input()
  b=[]
  for j in range(w):b.append(a[j])
  c+=b.count("#")
print("Possible"if h+w-1==c else"Impossible")