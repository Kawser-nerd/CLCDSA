import numpy as np
n = int(input())
Ans = [100 for _ in range(26)]
for _ in range(n):
    alp = [0 for _ in range(26)]
    s = input()
    for i in s:
        alp[ord(i)-97] += 1
    Ans = np.minimum(Ans, alp) 
ans = ''
for i in range(26):
    ans += chr(97+i)*Ans[i]
print(ans)