n = int(input())
D = len(bin(n))-2
def f():
    x = 1
    for d in range(100):
        if d%2 == D%2:
            x *= 2
        else:
            x = 2*x+1
        if x > n:
            break
    return d
if f()%2:
    print("Takahashi")
else:
    print("Aoki")