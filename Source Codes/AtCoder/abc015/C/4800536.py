N, K = map(int , input().split())
T = []
def func (v, T):
  if len(T) ==0:
    return v == 0
  tt = T[0]
  new_T = [a for a in T]
  new_T.pop(0)
  for t in tt:
    if func(t^v, new_T):
      return True
  return False

for i in range(N):
  T.append(list(map(int, input().split())))
if func(0, T):
  print("Found")
else:
  print("Nothing")