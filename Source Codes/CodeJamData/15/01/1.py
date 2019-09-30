t=input()
for j in xrange(t):
  smax,shy=raw_input().strip().split()
  maxshortage=0
  #At the start, we have exactly enough people standing to get
  #the next people to stand
  shortage=0 
  for k in xrange(len(shy)):
    #Check if the number of people we needed to make THIS person stand
    #was a record
    if shortage>maxshortage:
      maxshortage=shortage
    #Calculate the number of people needed to make the next person stand
    shortage+=1-int(shy[k])
  print "Case #"+str(j+1)+": "+str(maxshortage)
