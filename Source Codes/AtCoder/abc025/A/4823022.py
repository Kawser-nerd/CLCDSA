S = input()
N = int(input())

l = []
for i in S:
    for j in S:
        l.append(i+j)
 
print(l[N-1])