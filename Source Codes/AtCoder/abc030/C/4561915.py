n,m = map(int,input().split())
x,y = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

i = 0
j = 0
ans = 0
start_a = a[i]
while True:
  
  while True:
    if b[j] < x+a[i]:
      j = j+1
      if j == m:
        print(ans)
        exit()
    else:
      end_b = b[j]
      ans +=1 
      break

  while True:
    if a[i] < y+b[j]:
      i = i+1
      if i == n:
        print(ans)
        exit()
    else:
      start_a = a[i]
      break
      
print(ans)