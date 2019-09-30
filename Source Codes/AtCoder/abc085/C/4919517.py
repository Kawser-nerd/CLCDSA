N,Y = map(int, input().split())
a = Y//10000
b = (Y%10000)//5000
c = (Y%5000)//1000
for i in range(a+1):
    x = a-i
    y = b + i * 2
    for j in range(y+1):
        z = c + j * 5
        if x+y-j+z == N:
            print("{} {} {}".format(x,y-j,z))
            exit()
        if x+y-j+z > N:
            break
print("-1 -1 -1")