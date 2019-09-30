C = [1,2,3,4,5,6]
a = 0
c = ''
N = int(input())
if N >= 30:
    N = N%30
for i in range(N):
    i = i%5
    a = C[i]
    C[i] = C[i+1]
    C[i+1] = a
for j in C:
    c = c+str(j)
print(c)