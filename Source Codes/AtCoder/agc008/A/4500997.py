def solve():
  x,y = (int(i) for i in input().split())
  ans = []
  #B 0?
  if x <= y:
    ans.append(y-x)
  #B 1?
  if -x <= y:
    ans.append(y+x+1)
  if x <= -y:
    ans.append(-y-x+1)
  #B 2?
  if -x <= -y:
    ans.append(x-y+2)
  return(min(ans))
  
  
  
if __name__ == '__main__':
  print(solve())