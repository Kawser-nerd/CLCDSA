s=input()
t=int(input())
x=abs(s.count("R")-s.count("L"))+abs(s.count("U")-s.count("D"))
y=s.count("?")
if t==1:
  print(x+y)
else:
  if x-y<0:
    if abs(x-y)%2==0:
      print(0)
    else:
      print(1)
  else:
    print(x-y)