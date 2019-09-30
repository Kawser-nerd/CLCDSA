import numpy as np

n = int(input())
ans = np.Inf

for i in range(1,int(n/2+1)):
    a = str(i)
    b = str(n - i)
    an = 0
    for j in range(len(a)):
        an += int(a[j])
    for k in range(len(b)):
        an += int(b[k])
    if an < ans:
        ans = an
print(ans)