from operator import itemgetter
N = int(input())
numlist = []
for n in range(N):
  s,p= input().split()
  numlist.append([s,int(p)])
numlist.sort(key = itemgetter(1),reverse=True)
if numlist[0][1]>sum([i[1] for i in numlist])//2:
      print(numlist[0][0])
else:
      print("atcoder")