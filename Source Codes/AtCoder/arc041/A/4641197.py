x,y = map(int,input().split())
k = int(input())
L = [0]*y + [1]*x
for i in range(k):
    if L[i] == 0:
        L[i] = 1
    else:
        L[i] = 0
print(sum(L))