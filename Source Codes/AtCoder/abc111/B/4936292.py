n = int(input())
x = n
while True:
    flag = False
    first_s = str(x)[0]
    if all(s == first_s for s in str(x)):
        print(x)
        exit()
    x += 1