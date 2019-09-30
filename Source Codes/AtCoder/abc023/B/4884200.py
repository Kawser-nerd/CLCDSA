n=int(input())
hoge=input()
if(len(hoge)%2==0):
  print(-1)
elif(hoge.count("a")+hoge.count("b")+
     hoge.count("c")!=len(hoge)):
  print(-1)
elif(hoge[len(hoge)//2]!="b"):
  print(-1)
else:
  hoge_r=hoge[::-1]
  flag=0
  for i in range(len(hoge)//2):
    if(hoge[i]=="a" and hoge_r[i]=="c"):
      flag+=0
    elif(hoge[i]=="b" and hoge_r[i]=="b"):
      flag+=0
    elif(hoge[i]=="c" and hoge_r[i]=="a"):
      flag+=0
    else:
      flag+=1
  if(flag!=0):
    print(-1)
  else:
    print(len(hoge)//2)