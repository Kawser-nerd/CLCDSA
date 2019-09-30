O=input()
E=input()
for i in range(len(O)+len(E)):
  if i%2==0:
    print(O[int(i/2)],end="")
  else:
    print(E[int((i-1)/2)],end="")