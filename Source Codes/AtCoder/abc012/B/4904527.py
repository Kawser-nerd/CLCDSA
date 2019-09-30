n=int(input())
ho=n//3600
if(ho<10):
  print(0,end="")
print(ho,end="")
print(":",end="")
mi=n//60 -ho*60
if(mi<10):
  print(0,end="")
print(mi,end="")
print(":",end="")
se=n -ho*3600 -mi*60
if(se<10):
  print(0,end="")
print(se)