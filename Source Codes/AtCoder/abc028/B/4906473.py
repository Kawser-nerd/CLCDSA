s=input()
a=[0,0,0,0,0,0]
b="ABCDEF"
for x in s:
  for i in range(6):
    if x==b[i]:
      a[i] +=1
 
print("{} {} {} {} {} {}".format(a[0],a[1],a[2],a[3],a[4],a[5]))