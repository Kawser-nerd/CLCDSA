N = int(input())
a = []



if N%2==1:
  a.append(1)

for i in range(N//2):
  a.append(2)

print(len(a))
for i in a:
    print(i)