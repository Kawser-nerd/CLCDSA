N = input()
mylist = []
for i in range(len(N)):
  mylist.append(N[i])
newlist = [int(s) for s in mylist]
divisor = 0
for j in range(len(newlist)):
  divisor += newlist[j]
N = int(N)
if N%divisor == 0:
  print("Yes")
else:
  print("No")