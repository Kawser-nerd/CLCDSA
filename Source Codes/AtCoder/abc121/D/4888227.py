a,b = map(int,input().split())
def f(x):
    if x % 2 ==1:
        if ((x-1)//2)%2==0:
            return 1
        else:
            return 0

    else:
        if ((x-2)//2)%2 == 0:
            return x^1
        else:
            return x
print(f(a-1)^f(b))