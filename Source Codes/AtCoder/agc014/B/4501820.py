def solve():
  n,m = (int(i) for i in input().split())
  a = [0]*n
  for i in range(m):
    a1,b1 = (int(i) for i in input().split())
    a[a1-1]+=1
    a[b1-1]+=1
  ans = 'YES'
  for i in range(n):
   if a[i]%2 == 1:
    ans ='NO'
  return ans
                   
  
if __name__ == '__main__':
  print(solve())