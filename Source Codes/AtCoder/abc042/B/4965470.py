n,l=map(int,input().split()) 
s = []
for i in range(n):
  s.append(input())

s = sorted(s)
print("".join(s))