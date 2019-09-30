def solve():
  a,b,c = (int(i) for i in input().split())
  queue = [[a,b,c]] #mugencheck
  ct = 0
  while ct <100000000:
    if a%2 ==1 or b%2 ==1 or c%2 == 1: break
    #???????simluration
    tmpa = a//2
    tmpb = b//2
    tmpc = c//2
    a = tmpb+tmpc
    b = tmpa+tmpc
    c = tmpa+tmpb
    if [a,b,c] in queue: 
      return -1
    else:
      ct += 1
      queue.append([a,b,c])
      #print(queue)
  return ct
                   
  
if __name__ == '__main__':
  print(solve())