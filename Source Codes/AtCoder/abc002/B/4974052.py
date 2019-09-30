W = input()
aiueo = ['a', 'i', 'u', 'e', 'o']
w = ''
for i in W:
  if not i in aiueo:
    w = w + i
print(w)