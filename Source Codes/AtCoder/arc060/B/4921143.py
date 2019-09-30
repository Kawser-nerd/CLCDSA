import itertools
import math 
 
n,s = [int(input()) for _ in range(2)]
 
def n_base_sum(n,b):
    if(math.floor(n/b)):
        return n_base_sum(math.floor(n/b),b)+n%b
    else:
        return n%b
 
def search_p(n,s):
    for p in range(math.floor(math.sqrt(n))+1,0,-1):
        b = (n-s)//p + 1
        if b >1 :
            q = n % b
            if p+q ==s and q < b and n == p*b+q and p<b:
                return b
        
    return -1
 
ans =-1
flag = False
answers = []
if s == n:
    ans = n+1
    flag =True
    answers.append(ans)
for b in  range(2,math.ceil(math.sqrt(n))+1):
    if s== n_base_sum(n,b):
        ans = b
        flag = True
        answers.append(ans)
        break
ans = search_p(n,s)
if ans != -1:
    flag =True
    answers.append(ans)
 
if not flag:
    print(-1)
else:
    print(int(min(answers)))