hoge=list(input())
flag=0
while 1:
  if(len(hoge)==0 and flag==0):
    print("YES")
    break
  elif(len(hoge)==0 and flag==1):
    print("NO")
    break
  elif(hoge[0]=="o" or hoge[0]=="k" or hoge[0]=="u"):
    hoge=hoge[1:]
  elif(len(hoge)>=2):
    if(hoge[0]=="c" and hoge[1]=="h"):
      hoge=hoge[2:]
    else:
      flag=1
      hoge=[]
  else:
    flag=1
    hoge=[]