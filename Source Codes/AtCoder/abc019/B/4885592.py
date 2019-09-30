hoge=input()
mae=" "
kazu=0
flag=0
for i in range(len(hoge)):
  moji=hoge[i]
  if(moji==mae):
    kazu+=1
  else:
    if(flag==0):
      flag=1
    else:
      print(kazu,end="")
      
    print(moji,end="")
    kazu=1
  mae=hoge[i]
print(kazu,end="")
print("")