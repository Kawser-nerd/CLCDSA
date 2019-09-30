hoa=list(input())
hob=list(input())
hoc=list(input())
f="A"

while 1:
  if(f=="A" and len(hoa)==0):
    print(f)
    break
  elif(f=="B" and len(hob)==0):
    print(f)
    break
  elif(f=="C" and len(hoc)==0):
    print(f)
    break
  elif(f=="A"):
    if(hoa[0]=="a"):
      f="A"
      hoa=hoa[1:]
    elif(hoa[0]=="b"):
      f="B"
      hoa=hoa[1:]
    elif(hoa[0]=="c"):
      f="C"
      hoa=hoa[1:]
  elif(f=="B"):
    if(hob[0]=="a"):
      f="A"
      hob=hob[1:]
    elif(hob[0]=="b"):
      f="B"
      hob=hob[1:]
    elif(hob[0]=="c"):
      f="C"
      hob=hob[1:]
  elif(f=="C"):
    if(hoc[0]=="a"):
      f="A"
      hoc=hoc[1:]
    elif(hoc[0]=="b"):
      f="B"
      hoc=hoc[1:]
    elif(hoc[0]=="c"):
      f="C"
      hoc=hoc[1:]