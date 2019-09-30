# -*- coding: utf-8 -*-
N=-1
M=-1
#def getI(num):
    #return num/W
    
#def getJ(num):
    #return num%W
  





if __name__=="__main__":
  global N,M
  fd=open("B-large.in","r")
  num=int(fd.readline().strip())
  print "numis ",num
  fw=open("outputSecondLarge","w")
  for caseI in range(num):
    
    sline=fd.readline().split()
    #print sline
    N=int(sline[0])
    M=int(sline[1])
    alt=[]
    hor=[]
    ver=[]
    wait=[]
    for i in range(N):
      line=fd.readline().split()
      temp1=[]
      temp2=[]
      temp3=[]
      index=0
      while index<len(line):
	temp1.append(int(line[index]))
	index=index+1
	temp2.append(int(line[index]))
	index=index+1
	temp3.append(int(line[index]))
	index=index+1
      hor.append(temp1)
      ver.append(temp2)
      wait.append(temp3)

    #print N,"  ",M
    #print wait
    
    
    #print "alt:"
    #for i in alt:
     #print i
    #ls=[]
    mat=[]
    for i in range(2*N):
      temp=[-1]*(2*M)
      mat.append(temp)
    mat[2*N-1][0]=0
    
    for k in range(4*N*M):
	for i in range(2*N):
	  for j in range(2*M):
	    if mat[i][j]==-1:
	      continue;
	    else:
	      if i<(2*N-1):
		if i%2==0:
		  t0=mat[i][j]
		  cycle=hor[i/2][j/2]+ver[i/2][j/2]
		  t1=wait[i/2][j/2]
		  add=0
		  if (t0-t1)%cycle >= hor[i/2][j/2]:
		    add=cycle-(t0-t1)%cycle
		  nextValid=t0+(add)
		  tempTime=nextValid+1
		  if mat[i+1][j]==-1 or mat[i+1][j]>tempTime:
		    mat[i+1][j]=tempTime
		else:
		  t0=mat[i][j]
		  tempTime=t0+2
		  if mat[i+1][j]==-1 or mat[i+1][j]>tempTime:
		    mat[i+1][j]=tempTime
	      if i > 0:
		if i%2!=0:
		  t0=mat[i][j]
		  cycle=hor[i/2][j/2]+ver[i/2][j/2]
		  t1=wait[i/2][j/2]
		  add=0
		  if (t0-t1)%cycle >= hor[i/2][j/2]:
		    add=cycle-(t0-t1)%cycle
		  nextValid=t0+(add)
		  tempTime=nextValid+1
		  if mat[i-1][j]==-1 or mat[i-1][j]>tempTime:
		    mat[i-1][j]=tempTime
		else:
		  t0=mat[i][j]
		  tempTime=t0+2
		  if mat[i-1][j]==-1 or mat[i-1][j]>tempTime:
		    mat[i-1][j]=tempTime
	      if j<(2*M-1):
		if j%2==0:
		  t0=mat[i][j]
		  cycle=hor[i/2][j/2]+ver[i/2][j/2]
		  t1=wait[i/2][j/2]+hor[i/2][j/2]
		  add=0
		  if (t0-t1)%cycle >= ver[i/2][j/2]:
		    add=cycle-(t0-t1)%cycle
		  nextValid=t0+(add)
		  #print "reached ",t0
		  tempTime=nextValid+1
		  if mat[i][j+1]==-1 or mat[i][j+1]>tempTime:
		    mat[i][j+1]=tempTime
		else:
		  t0=mat[i][j]
		  tempTime=t0+2
		  if mat[i][j+1]==-1 or mat[i][j+1]>tempTime:
		    mat[i][j+1]=tempTime
	      if j > 0:
		if j%2!=0:
		  t0=mat[i][j]
		  cycle=hor[i/2][j/2]+ver[i/2][j/2]
		  t1=wait[i/2][j/2]+hor[i/2][j/2]
		  add=0
		  if (t0-t1)%cycle >= ver[i/2][j/2]:
		    add=cycle-(t0-t1)%cycle
		  nextValid=t0+(add)
		  tempTime=nextValid+1
		  if mat[i][j-1]==-1 or mat[i][j-1]>tempTime:
		    mat[i][j-1]=tempTime
		else:
		  t0=mat[i][j]
		  tempTime=t0+2
		  if mat[i][j-1]==-1 or mat[i][j-1]>tempTime:
		    mat[i][j-1]=tempTime
	#print "\n\nmat"
	#for l in mat:
	  #print l
	
    print mat[0][2*M-1]
    fw.write("Case #"+str(caseI+1)+": "+str(mat[0][2*M-1])+"\n")

    
  
      

  
