p = int(input())

a = p*p
b = (p+1)*(p+1)
if a + (100-a%100)%100 >=b:
    print(a)
else:
    num = 100
    while num < a:
        sub = (num-(a%num))%num
        if a+sub >= b:
            break
        a += sub
        num *= 100

    while a%100==0:
        a//=100
    print(a)