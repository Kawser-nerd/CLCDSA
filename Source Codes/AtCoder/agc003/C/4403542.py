n = int(input())
info =[]

for i in range(n):
  info.append([int(input()),i])
info = sorted(info)
  
ans = 0
for i in range(n):
  if i%2 != info[i][1]%2:
    ans = ans+1
print(ans//2)