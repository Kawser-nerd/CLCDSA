n = int(input())
cnt = 0
ch = 0
*w, = map(str,input().split())
#print(w)
for i in w:
  for j in i:
    #print(j)
    if j == 'I':
      cnt+=1
    elif j == 'D':
      cnt-=1
    if cnt > ch:
      ch = cnt
print(ch)