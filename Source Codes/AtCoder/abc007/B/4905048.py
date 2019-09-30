n=input()

if(n=="a"):
  print(-1)
elif(len(n)>1):
  for i in range(len(n)-1):
    print("a",end="")
  print("")
else:
  print("a")