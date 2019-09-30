import copy as co

class circle():
  def __init__(self, numlist,amount_of_can):
    self.numcircle=numlist
    self.til=0
    self.cansee=amount_of_can
    self.times=1
  def right_rotation(self,num,length):
    a=self.numcircle[:length-num]
    b=self.numcircle[length-num:]
    return b+a

def sup_and(str1,str2,length):
  count=0
  for x in range(0,length):
    str1[x]=str1[x] or str2[x]
    count+=str1[x]
  return count

def search(circlelist,length,TV):
  list1=[]
  for x in range(circlelist.til+1,length):
    circlelist2=co.deepcopy(circlelist)
    circlelist2.cansee=sup_and(circlelist2.numcircle,TV.right_rotation(x,length),length)
    circlelist2.til=x
    circlelist2.times+=1
    list1.append(circlelist2)
  return list1

inp1=input()
amount_of_can=0
numlist=[]
for x in inp1:
  if x=='x':
    numlist.append(0)
  else:
    numlist.append(1)
    amount_of_can+=1

length=len(numlist)

if amount_of_can==length:
  print(1)
  exit()
else:
  circlelist=circle(numlist,amount_of_can)
  alllist1=[circlelist]
  TV=co.deepcopy(circlelist)
  
  while True:
    alllist2=[]
    while alllist1:
      alllist2.extend(search(alllist1.pop(),length,TV))
    alllist1=alllist2
    for x in alllist1:
      if x.cansee==length:
        print (x.times)
        exit()