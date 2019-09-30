n=int(input())
if(n<100):
  print("00")
elif(n<1000):
  print("0",end="")
  print(n//100)
elif(n<6000):
  print(n//100)
elif(n<=30000):
  print(int(50 + n//1000))
elif(n<=70000):
  print(int(80+(-30+n//1000)//5))
else:
  print("89")