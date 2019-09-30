a,b=map(int,input().split())
if a*b<=0:print("Zero")
elif 0<a:print("Positive")
else:
  if (b-a)%2==1:print("Positive")
  else:print("Negative")