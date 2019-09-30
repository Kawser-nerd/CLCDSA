N = int(input())
ls = [0,9,18,27,36,45,54]
ans = ''
if N%9 == 0:
    ans = '9'
else:
    ans = str(N%9)
for i, (x, y) in enumerate(zip(ls, ls[1:])):
    if x < N and N <= y:
        print(ans*(i+1))