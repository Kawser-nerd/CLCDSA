input()
x,mx=0,0
for w in input():
  #print(w)
  x+=1 if w=='I' else -1
  mx = max(x,mx)
print(mx)