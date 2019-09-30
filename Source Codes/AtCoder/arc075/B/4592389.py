n,a,b = map(int,input().split())
h = [int(input()) for i in range(n)]
def judige(n):
    global h,a,b
    check = 0
    for i in range(len(h)):
        num = h[i]
        num -= b*n
        if num > 0:
            check += num//(abs(b-a)) if num % abs(b-a) == 0 else num//abs(b-a) + 1
    if check <= n:return True
    return False
inf = max(h)//b + 1
zero = 0
while True:
    num = (inf+zero)//2
    if inf-zero==1 or inf-zero==0:break
    if judige(num):inf = num
    else:zero = num
if judige(zero-2) and zero > 2:print(zero-2)
elif judige(zero-1) and zero > 1:print(zero-1)
elif judige(zero):print(zero)
else:print(inf)