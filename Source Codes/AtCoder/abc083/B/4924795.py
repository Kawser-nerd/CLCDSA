n,a,b = [int(_) for _ in input().split()]

result = []
for i in range(1,n+1): # n=20???1~20??????
  i = str(i)
  wa = 0
  for j in range(0,len(str(i))): # str????????????????????0???????1???????????????????
    wa = wa + int(i[j])
  if a <= wa <= b:
    result.append(int(i))

print(sum(result))