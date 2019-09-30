ren = int(input())
hanaar = str(input()).split(" ")

su = 0

for num in range(ren):
  
  nu = int(hanaar[num])
  
  for i in range(nu):
    if nu % 2 == 0:
      nu = nu - 1
      su = su + 1
    elif nu > 2 and (nu - 2) % 3 == 0:
      nu = nu - 1
      su = su + 1
    else:
      break
      
print(su)