abc = []
for i in range(0,3):
  abc.append(int(input()))
  
tmp = sorted(abc,reverse = True)

for i in abc:
  print(tmp.index(i)+1)