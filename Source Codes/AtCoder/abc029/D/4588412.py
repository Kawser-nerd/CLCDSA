n = int(input())

len_n = len(str(n))
ans = 0
for i in range(len_n):
  ans += (n//(10**(i+1)))*(10**(i))
#  print((n//(10**(i+1)))*(10**(i)))
  if int(str(n)[-(i+1)]) > 1:
    ans += 10**i
#    print(10**i)
  elif int(str(n)[-(i+1)]) == 1:
    ans += n% (10**i)+1
    
print(ans)