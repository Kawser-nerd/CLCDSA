N = int(input())

def factorical(n):
  ret = 0
  for i in range(1,n+1):
    ret += i
  return ret

print(factorical(N))