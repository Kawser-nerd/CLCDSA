n,l = map(int,input().split())
a = list(map(int,input().split()))

renzoku_length = [0]*n
last_undo = -1
for i in range(1,n):
  renzoku_length[i] = a[i]+a[i-1]
  if renzoku_length[i]>=l:
    last_undo =i
    break

if last_undo ==-1:
  print("Impossible")
  exit()

print("Possible")

for i in range(1,last_undo):
  print(i)
for i in range(last_undo+1,n)[::-1]:
  print(i)
print(last_undo)