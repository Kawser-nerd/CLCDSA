n = 2025-int(input())
for i in range(1,10):
    for j in range(1,10):
        if n == i*j:
            print(i,j,sep=" x ")