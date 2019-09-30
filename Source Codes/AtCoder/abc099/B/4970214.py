def sigma(num):
  ret=0
  for i in range(num+1):
    ret+=i
  return ret

n,m=map(int,input().split())
a=sigma(m-n)
print(a-m)