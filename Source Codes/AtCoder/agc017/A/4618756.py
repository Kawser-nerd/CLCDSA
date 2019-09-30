N,P = map(int,input().split())
Odd = sum([int(i)%2 for i in input().split()])
Even = N-Odd

def f_C(x,y):
    ans = 1
    for i in range(y):  
        ans *= x-i
    for i in range(y):  
        ans //= i+1
    return(ans)

ans = 2**Even
tmp = 0
for i in range(P,Odd+1,2):
    tmp += f_C(Odd,i)
print(ans*tmp)