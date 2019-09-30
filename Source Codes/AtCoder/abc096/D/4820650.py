era = [1]*55556

era[0] = era[1] = 0
for i in range(2,int(55556**0.5)+1):
    if( era[i] == 1):
        for j in range(i*2,55556,i): era[j] = 0

v = [0]*5
n = int(input())
for i in range(55556):
    if(era[i] and i%5 == 1):
        print(i, end=" ")
        n -= 1
        if(n == 0): break
print()