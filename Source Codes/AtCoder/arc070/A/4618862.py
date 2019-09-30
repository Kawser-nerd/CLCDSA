X = int(input())
a =0
for i in range(1,10**9):
    a += i    
    if a>=X:
        print(i)
        break