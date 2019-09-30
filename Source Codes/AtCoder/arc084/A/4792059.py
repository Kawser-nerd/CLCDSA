N = int(input())
A = [[int(a),"A"] for a in input().split()]
B = [[int(b),"B"] for b in input().split()]
C = [[int(c),"C"] for c in input().split()]

parts = A+B+C
parts.sort(key = lambda x:x[1])
parts.sort(reverse = True,key = lambda x:x[0])

A_pat = [0]  
B_pat = [0]
C_count = 0

for s,t in parts:
    if t=="C":      
        C_count += 1
    elif t=="B":
        B_pat.append(C_count+B_pat[-1])
    elif t=="A":
        A_pat.append(B_pat[-1]+A_pat[-1])
print(A_pat[-1])