from collections import Counter
a=Counter(list(input().strip()))
x=0
y=0
for i,j in a.most_common():
  x+=j//2
  if j%2==1:
    y+=1

print(x//y *2 + 1 if y>=1 else x*2)