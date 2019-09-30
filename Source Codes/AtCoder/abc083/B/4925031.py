n,a,b = [int(_) for _ in input().split()]

result = []
for seisu in range(1,n+1):

  wa = 0
  first_seisu = seisu

  while seisu != 0:
    wa = wa + seisu % 10
    seisu = int(seisu/10)

  if a <= wa <= b:
    result.append(first_seisu)

print(sum(result))