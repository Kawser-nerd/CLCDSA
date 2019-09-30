O, E = input(), input()

ans = ''
if len(O) == len(E):
  for i in range(len(O)):
    ans += O[i]
    ans += E[i]
elif len(O) - len(E) == 1:
  for i in range(len(E)):
    ans += O[i]
    ans += E[i]
  else:
    ans+=O[-1]
    
print(ans)