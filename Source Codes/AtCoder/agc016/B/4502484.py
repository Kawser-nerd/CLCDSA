#https://img.atcoder.jp/agc016/editorial.pdf
def solve():
  n = int(input())
  a = list(int(i) for i in input().split())
  ans = 'Yes'
  alone = 0
  group = 0
  ha = max(a)
  la = min(a)
  if ha - la >= 2: ans = 'No'
  
  elif ha - la == 1:
   for i in a:
     if i == ha-1 : alone += 1
     else: group += 1
   if alone < ha and 2*(ha-alone)<= group: pass
   else: ans = 'No'
  
  
  elif ha - la == 0:
    if a[0] == n-1 or 2*a[0] <= n:
      pass
    else: ans = 'No'
  return ans

if __name__ == '__main__':
  print(solve())