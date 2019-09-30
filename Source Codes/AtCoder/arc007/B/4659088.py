inp1=input ()
inp1=inp1.split(' ')
inp1[0]=int(inp1[0])
inp1[1]=int(inp1[1])

case=[x for x in range(0,inp1[0]+1)]
caselist=dict(zip(case,case))

listening=0
count=0
while (count<inp1[1]):
  inp2=int(input())
  caselist[listening]=caselist[inp2]
  caselist[inp2]=0
  listening=inp2
  count+=1
out={y:x for x,y in caselist.items()}
for x in range(1,inp1[0]+1):
  print (out[x])