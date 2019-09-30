N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))

P.append(a)
P.append(b)
#print(P)

if len(P) == len(list(set(P))):
  print('YES')
else:
  print('NO')