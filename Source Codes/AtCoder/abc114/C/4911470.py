n=int(input())
import bisect
import itertools
l=len(str(n))
ans=[]
num=[]
x=['3', '5', '7']
for k in range(3,l+1):
    m=list(itertools.product(x, repeat=k))
    num.extend(m)
for i in range(len(num)):
    y=num[i]
    if '3' in y and '5' in y and '7' in y:
        number=''
        for j in range(len(y)):
            number+=y[j]
        ans.append(int(number))
ans.sort()
print(bisect.bisect_right(ans, n))