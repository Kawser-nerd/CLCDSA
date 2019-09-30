A,B,K = map(int, input().split())
mylist = []
for i in range(1,max(A,B)+1):
  if A%i == 0 and B%i == 0:
    mylist.append(i)
newlist = sorted(mylist, reverse = True)
print(newlist[K-1])