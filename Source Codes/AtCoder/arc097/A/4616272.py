s = input()
K = int(input())
L = []
for i in range(5):
  for j in range(len(s)-i):
    L.append(s[j:j+i+1])
L = list(set(L))
L.sort()
print(L[K-1])