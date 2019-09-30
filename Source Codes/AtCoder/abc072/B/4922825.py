A=input()
B=[]
for i,v in enumerate(A):
    if i%2==0:
         B.append(v)
    else:
        continue
print("".join(B))