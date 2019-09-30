s = int(input())
def f(x):
    if x%2 == 0:
        return int(x/2)
    else:
        return int(3*x+1)
a =[s]
for i in range(1,1000000):
    b = f(a[i-1])
    if b in a:
        print(i+1)
        break
    else:
        a.append(b)