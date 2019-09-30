d={str(j):str(i) for i,j in enumerate(map(int,input().split()))}
e={j:i for i,j in d.items()}
n=int(input())
a=[input() for _ in range(n)]

for i in range(n):
  a[i] = int(a[i].translate(str.maketrans(d)))
a.sort()
 
for i in range(n):
  print(str(a[i]).translate(str.maketrans(e)))