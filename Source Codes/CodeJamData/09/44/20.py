import sys,math
fi=open(sys.argv[1],"r")
fo=open(sys.argv[2],"w")
cases=int(fi.readline())
for C in range(cases):
  plants=int(fi.readline())
  P=[]
  for plant in range(plants):
    P.append(map(int,fi.readline().split()))
  R={}
  for a in range(plants):
    for b in range(a,plants):
      R[(a,b)]=math.sqrt((P[a][0]-P[b][0])**2+(P[a][1]-P[b][1])**2)+P[a][2]+P[b][2]
  if(plants==1): fo.write("Case: #%d: %f\n"%(C+1,P[0][2]))
  if(plants==2): fo.write("Case: #%d: %f\n"%(C+1,max(P[0][2],P[1][2])))
  if(plants==3):
    m=min(R[(0,1)],R[(0,2)],R[(1,2)])
    if R[(0,1)]==m: fo.write("Case #%d: %f\n"%(C+1,max(m/2.0,P[2][2])))
    elif R[(0,2)]==m: fo.write("Case #%d: %f\n"%(C+1,max(m/2.0,P[1][2])))
    elif R[(1,2)]==m: fo.write("Case #%d: %f\n"%(C+1,max(m/2.0,P[0][2])))

fi.close()
fo.close()
