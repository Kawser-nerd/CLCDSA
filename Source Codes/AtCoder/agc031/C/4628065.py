# coding: utf-8
# Your code here!
import sys

def sum_digits(n,m):
   r = 0
   while n:
       r, n = r + n % m, n // m
   return r


n,a,b = [int(i) for i in input().split()]

c=a^b
if sum_digits(c,2)%2 == 0:
   print('NO') 
   sys.exit()

def grey(n):
    if n == 1: return [0,1]
    a0 = grey(n-1)
    a2= [(2**(n-2))^i^(2**(n-1)) for i in grey(n-1)] 
    return a0 + a2
    #print(grey(4))

def newgrey(a,b,move):
    if len(move) == 1:
        return [a,b]
    diff = 0
    for j in move:
        if a&(2**j) != b&(2**j):
            diff=j
            break
    ac = a
    bc = b
    for j in move:
        if j == diff: continue
        ac = a^(2**j)
        bc = ac ^ (2**diff)
        if bc != b: break
    return newgrey(a,ac, move-set({diff})) + newgrey(bc,b, move-set({diff}))
    
print('YES')
ans =newgrey(a,b,set(range(n)))
print(*ans)