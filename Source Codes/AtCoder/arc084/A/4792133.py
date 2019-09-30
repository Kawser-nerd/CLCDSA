N = int(input())
A = [[int(a),"A"] for a in input().split()]
B = [[int(b),"B"] for b in input().split()]
C = [[int(c),"C"] for c in input().split()]

parts = A+B+C
parts.sort(reverse = True,key = lambda x:x[0])

A_count = 0  
B_count = 0  
C_count = 0

for s,t in parts:
    if t=="C":      
        C_count += 1
    elif t=="B":
        B_count += C_count             
    elif t=="A":
        A_count += B_count
print(A_count)