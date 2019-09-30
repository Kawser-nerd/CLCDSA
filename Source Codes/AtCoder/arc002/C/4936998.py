import itertools
N = int(input())
C = input()

min_cost = float('inf')
seq = ['A','B','X','Y']
Comb = list(itertools.product(seq, seq,seq,seq))
for i in range(len(Comb)):
 tmp = list(Comb[i])
 s1,s2 = tmp[0]+tmp[1],tmp[2]+tmp[3]
 C1 = C.replace(s1,'L').replace(s2, 'R')
 C2 = C.replace(s2,'L').replace(s1, 'R') 
 min_cost = min(len(C1),len(C2),min_cost) 

print(min_cost)