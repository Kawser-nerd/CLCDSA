a=int(input())
for i in range(a):
    if i*(i+1)//2<=a and a<=(i+1)*(i+2)//2:
        print(i+1)
        break