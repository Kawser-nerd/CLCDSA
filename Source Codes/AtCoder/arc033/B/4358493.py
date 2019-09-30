NA, NB = list(map(int, input().split()))
AList = list(map(int, input().split()))
BList = list(map(int, input().split()))

AB = AList + BList

AB.sort()

counter = 0
N = len(AB)
Ntmp = N
i = 0
while i < N - 1:
  if AB[i] == AB[i+1]:
    counter+=1
    Ntmp -= 1
    i+=1
  i+=1

print(counter / Ntmp)