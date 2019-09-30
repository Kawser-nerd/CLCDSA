def solve():
  s = input()
  n = int(input())
  for i in range(n):
    l,r = (int(i) for i in input().split())
    tmp = s[l-1:r]
    #print(tmp)
    s = s[0:l-1]+tmp[::-1]+s[r::]
  print(s)
solve()