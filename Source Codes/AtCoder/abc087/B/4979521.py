cnt500=int(input())
cnt100=int(input())
cnt50=int(input())
price=int(input())

cnt=0
for a in range(cnt500+1):
  if cnt500*a > price:
    break
  for b in range(cnt100+1):
    if cnt100*b > price:
      break
    for c in range(cnt50+1):
      if cnt50*c > price:
        break
      if a*500+b*100+c*50 == price:
        cnt+=1
print(cnt)