from itertools import permutations
C = []
for i in range(8):
  C.append(list(input()))
  
# 61C5 = 61*60*59*58*57 / 120
# 5P5=120???????????
# ????????x-y??? or x+y???

Qlist = []
xlist = list(range(8))
ylist = list(range(8))

for i in range(8):
  for j in range(8):
    if C[i][j] == "Q":
      Qlist.append([i,j])
      try:
        xlist.remove(i)
        ylist.remove(j)
      except ValueError:
        print("No Answer")
        exit(0)
        
#print(Qlist)
#print(xlist, ylist)

for p in permutations(xlist):
  x_p_y, x_m_y = set(), set()
  for el in Qlist:
    #print(el)
    x_p_y.add(el[0] + el[1])
    x_m_y.add(el[0] - el[1])
  
  temp = list(p)
  for i in range(5):
    x_p_y.add(p[i] + ylist[i])
    x_m_y.add(p[i] - ylist[i])
  
  if len(x_p_y) >= 8 and len(x_m_y) >= 8:
    for i in range(5):
      Qlist.append([temp[i],ylist[i]])
      
    ans = [["."] * 8 for i in range(8)]
    for el in Qlist:
      ans[el[0]][el[1]] = "Q"
      
    for i in range(8):
      print("".join(ans[i]))    
    exit(0)
 
print("No Answer")