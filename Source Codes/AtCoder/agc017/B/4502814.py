import math
def solve():
  n,a,b,c,d = (int(i) for i in input().split())
  if a > b: a,b = b,a
  ans = 'NO'
  for i in range(n):
    if a+ i*c -(n-i-1)*d <= b <= a + i * d - (n - i - 1) * c:
     ans ='YES'
  return ans
if __name__ == '__main__':
  print(solve())