# coding: utf-8

def solve(a,begin,end,queue):
  if begin>=end:
    return
  maxx = sorted(list(map(abs,a[begin:end+1])),reverse=True)[0]
  if maxx in a[begin:end+1]:
    m = a[begin:end+1].index(maxx)+begin
  else:
    m = a[begin:end+1].index(-1*maxx)+begin
    maxx = -1*maxx
  if maxx==0:
    return []
  if maxx>0:
    solve(a,begin,m-1,queue)
    for i in range(max(0,m-1),end):
      if a[i+1]>=a[i]:
        continue
      else:
        a[i+1]+=a[i]
        queue.append((i,i+1))
        if a[i+1]<a[i]:
          a[i+1]+=a[i]
          queue.append((i,i+1))
    return queue
  if maxx<0:
    solve(a,m+1,end,queue)
    for i in reversed(range(begin,min(len(a)-1,m+1))):
      if a[i]<=a[i+1]:
        continue
      else:
        a[i]+= a[i+1]
        queue.append((i+1,i))
        if a[i]>a[i+1]:
          a[i]+=a[i+1]
          queue.append((i+1,i))
    return queue

if __name__ == '__main__':
  n = int(input())
  a = list(map(int,input().split()))
  queue = solve(a,0,len(a)-1,[])
  print(len(queue))
  for i in range(len(queue)):
    print(queue[i][0]+1,queue[i][1]+1)