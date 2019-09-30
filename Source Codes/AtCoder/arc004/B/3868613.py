N = int(input())

d = []
for i in range(N):
    inputd = int(input())
    d.append(inputd)

biggest = sum(d)

if max(d) >= biggest/2 :
    smallest = abs(max(d) - (sum(d) - max(d)))
else:
    smallest = (0)
    

print(biggest)
print(smallest)