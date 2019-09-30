N = int(input())
count = 0
morta = 0


for i in range(N):
    count+=800
    if (i+1)%15==0:
        morta += 200

print(count-morta)