import numpy as np
a,b,k = map(int,input().split())
c = np.array(list(range(1,min(a,b)+1))) #a,b????????????????
#????????????????????????k????????????c?print
e = [f for f,g in enumerate(zip(a%c,b%c)) if g == (0,0)]
print(c[e[-k]])