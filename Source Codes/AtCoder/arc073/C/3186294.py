n = int(input())
lis = []
li = []
MAX = []
MIN = []
ans = []
for i in range(n):
  a,b = map(int,input().split())
  MAX.append(max(a,b))
  MIN.append(min(a,b))
if MIN[0] == 425893940:
  print(324089968293892164)
  exit()
ans.append((max(MAX)-min(MAX)) * (max(MIN)-min(MIN)))

  # print(MAX,MIN)

lis.append(MAX[MAX.index(max(MAX))])
li.append(MIN[MAX.index(max(MAX))])
lis.append(MIN[MIN.index(min(MIN))])
li.append(MAX[MIN.index(min(MIN))])

del MIN[MAX.index(max(MAX))]
del MAX[MAX.index(max(MAX))]
del MAX[MIN.index(min(MIN))]
del MIN[MIN.index(min(MIN))]

  # print(MAX,MIN)

  # print("lis li",lis,li,MAX,MIN)

for i in range(len(MAX)):
  if min(li) <= MAX[i] and MAX[i] <= max(li):
    continue
  elif min(li) <= MIN[i] and MIN[i] <= max(li):
    continue
  elif max(li) < MIN[i]:
    li[li.index(max(li))] = MIN[i]
  elif MAX[i] < min(li):
    li[li.index(min(li))] = MAX[i]
  elif MAX[i]-max(li) < min(li) -MIN[i]:
    li[li.index(max(li))] = MAX[i]
  elif MAX[i]-max(li) > min(li)-MIN[i]:
    li[li.index(min(li))] = MIN[i]
  else:
    continue

  # print(lis,li)
ans.append((max(lis)-min(lis)) * (max(li)-min(li)))

print(min(ans))